#ifndef SRP_USERMANAGER_H
#define SRP_USERMANAGER_H


#include <string>
#include "DbService.h"
#include "SmtpClient.h"

class UserManager {
    DbService db;
    SmtpClient smtp;

    std::string hash(std::string const& password) {
        return password + " is now hashed";
    }

public:
    void registerUser(std::string const& email, std::string const& password) {
        if (email.find('@') == std::string::npos) {
            throw std::invalid_argument("The email is not valid.");
        }

        User user;
        user.email = email;
        user.password = hash(password);
        user.created = std::chrono::system_clock::now();

        db.connect("postgres-host:database-name");
        db.save(user);
        db.release();

        smtp.setParameter("smtp.server", "smtp.example.tld");
        smtp.sendEmail("our-admin@example.tld", "Registration Message", "Welcome Our Dear Client!");
    }

};


#endif //SRP_USERMANAGER_H
