#include "User.h"

User::User() {}
User::~User() {}

int User::getID() const                  { return _ID; }

std::string User::getLogin() const       { return _login; }
std::string User::getPassword() const    { return _password; }
std::string User::getName() const        { return _name; }

