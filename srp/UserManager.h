#ifndef SRP_USERMANAGER_H
#define SRP_USERMANAGER_H


#include <string>
#include <stdexcept>
#include "DbService.h"
#include "SmtpClient.h"
#include "Email.hpp"
#include "Password.hpp"
#include "DatabaseUrl.hpp"

class UserManager {
    DbService db;
    SmtpClient smtp;

public:
    void registerUser(Email email, Password password)
    {
        User user{std::move(email), std::move(password)};
        db.saveUser(user);
        smtp.greetNewMember(
            Email{"our-admin@example.tld"},
            user.getEmail(),
            GreetingMessage{"Registration Message", "Welcome Our Dear Client!"});
    }

};


#endif //SRP_USERMANAGER_H
