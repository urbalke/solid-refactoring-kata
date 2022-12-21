#include "SmtpClient.h"
#include <algorithm>

SmtpClient::SmtpClient(std::vector<SmtpClientParameter> p_parameters) : m_SmtpClientParameters(std::move(p_parameters))
{
    std::for_each(p_parameters.begin(), p_parameters.end(), setParameter);
}

void SmtpClient::greetNewMember(Email const& p_from, Email const& p_to, GreetingMessage const& p_message)
{
    sendEmail(p_from.getEmail(), p_to.getEmail(), p_message);
}

void SmtpClient::setParameter(SmtpClientParameter const&) {}
void SmtpClient::sendEmail(std::string const& from, std::string const& to, GreetingMessage const&) {}