#ifndef SRP_USER_H
#define SRP_USER_H


#include <string>
#include <chrono>
#include "Email.hpp"
#include "Password.hpp"

class User
{
public:
    User(Email p_email, Password p_password)
        : email(std::move(p_email)), password(std::move(p_password)), created(std::chrono::system_clock::now()) {}

    const Email& getEmail() const
    {
        return email;
    }
private:
    Email email;
    Password password;
    std::chrono::time_point<std::chrono::system_clock> created;
};


#endif //SRP_USER_H
