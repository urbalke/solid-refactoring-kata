#pragma once

#include <string>
#include <stdexcept>

class Email
{
public:
    Email(std::string p_email) : m_email(std::move(p_email))
    {
        validate();
    }

    const std::string& getEmail() const
    {
        return m_email;
    }
private:
    void validate() const
    {
        if (m_email.find('@') == std::string::npos)
        {
            throw std::invalid_argument("The email is not valid.");
        }

    }
    std::string m_email;
};