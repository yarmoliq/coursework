#include "User.h"


//User::User(std::string id, AccessLevel al, std::string login,
//    std::string password, std::string name)
//{
//    _id = id;
//    _accessLevel = al;
//    _login = login;
//    _password = password;
//    _name = name;
//}

//std::vector<std::string> User::convertObject() const
//{
//    
//}

User::User(const std::string(&params)[5])
{
    _id = params[0];
    _accessLevel = (User::AccessLevel)std::stoi(params[1]);
    _login = params[2];
    _password = params[3];
    _name = params[4];
}

User::~User() {}


User::AccessLevel User::getAccessLevel() const   { return _accessLevel; }

std::string User::getLogin() const               { return _login; }
std::string User::getPassword() const            { return _password; }
                                                 
std::string User::getName() const                { return _name; }