#include "User.h"

User::User(Email p_email, Password p_password)
    : email(std::move(p_email)), password(std::move(p_password)), created(std::chrono::system_clock::now()) {}

const Email& User::getEmail() const
{
    return email;
}