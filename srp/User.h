#pragma once

#include <string>
#include <chrono>
#include "Email.hpp"
#include "Password.hpp"

class User
{
public:
    User(Email, Password);
    const Email& getEmail() const;

private:
    Email email;
    Password password;
    std::chrono::time_point<std::chrono::system_clock> created;
};