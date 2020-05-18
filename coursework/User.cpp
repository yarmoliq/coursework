#include "User.h"

User::User(std::string ID, User::AccessLevel AL, std::string login,
           std::string password, std::string name)
{
    _ID              = ID;
    _accessLevel     = AL;
    _login           = login;
    _password        = password;
    _name            = name;
}
User::~User() {}

std::string User::getID() const                  { return _ID; }

User::AccessLevel User::getAccessLevel() const   { return _accessLevel; }

std::string User::getLogin() const               { return _login; }
std::string User::getPassword() const            { return _password; }
                                                 
std::string User::getName() const                { return _name; }