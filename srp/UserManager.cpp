#include "UserManager.h"

UserManager::UserManager(DatabaseUrl databaseUrl , std::vector<SmtpClientParameter> p_smtpParams)
        : db(std::move(databaseUrl.get())), smtp(std::move(p_smtpParams)) {}

void UserManager::registerUser(Email email, Password password)
{
    User user{std::move(email), std::move(password)};
    db.saveUser(user);
    smtp.greetNewMember(
        Email{"our-admin@example.tld"},
        user.getEmail(),
        GreetingMessage{"Registration Message", "Welcome Our Dear Client!"});
}