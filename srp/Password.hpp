#pragma once

#include <string>

class Password
{
public:
    Password(std::string p_unHashedPassword) : m_hashedPassword(hash(std::move(p_unHashedPassword))) {}

private:
    std::string hash(std::string password)
    {
        password += " is now hashed";
        return std::move(password);
    }
    std::string m_hashedPassword;
};