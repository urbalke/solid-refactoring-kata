#pragma once

#include <string>
#include "Email.hpp"
#include <vector>

struct SmtpClientParameter
{
    std::string m_name;
    std::string m_value;
};

struct GreetingMessage
{
    std::string m_subject;
    std::string m_body;
};

class SmtpClient {
public:

    SmtpClient(std::vector<SmtpClientParameter>);
    void greetNewMember(Email const&, Email const&, GreetingMessage const&);

private:
    static void setParameter(SmtpClientParameter const&);
    void sendEmail(std::string const&, std::string const&, GreetingMessage const&);

    std::vector<SmtpClientParameter> m_SmtpClientParameters;
};