#ifndef SRP_SMTPCLIENT_H
#define SRP_SMTPCLIENT_H


#include <string>

class SmtpClient {
public:
    void setParameter(std::string const &name, std::string const &value) {}
    void sendEmail(std::string const &from, std::string const &subject, std::string const &body) {}
};


#endif //SRP_SMTPCLIENT_H
