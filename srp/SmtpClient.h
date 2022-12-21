#ifndef SRP_SMTPCLIENT_H
#define SRP_SMTPCLIENT_H

#include <string>
#include "Email.hpp"

struct SmtpClientParameters
{
    std::string m_key;
    std::string m_value;
};

struct GreetingMessage
{
    std::string m_subject;
    std::string m_body;
};

class SmtpClient {
public:
    SmtpClient() : m_smtpClientParameters(SmtpClientParameters{"smtp.server", "smtp.example.tld"}) {}
    void greetNewMember(Email const& p_from, Email const& p_to, GreetingMessage const& p_message);

private:
    void setParameter(std::string const &name, std::string const &value) {}
    void sendEmail(std::string const& from, std::string const& to, std::string const &subject, std::string const &body) {}

    SmtpClientParameters m_smtpClientParameters;
};


#endif //SRP_SMTPCLIENT_H
