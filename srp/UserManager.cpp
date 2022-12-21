#include "UserManager.h"

void SmtpClient::greetNewMember(Email const& p_from, Email const& p_to, GreetingMessage const& p_message)
{
    sendEmail(p_from.getEmail(), p_to.getEmail(), p_message.m_subject, p_message.m_body);
}