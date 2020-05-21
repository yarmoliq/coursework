#include "User.h"

User::User(const Arguments &args)
{
    if (args.size() != 5)
        throw "wrong arguments";

    try {
        _id = std::stoi(args[0]);
    }
    catch (const char e) { throw "bad id argument"; }

    try {
        _accessLevel = (AccessLevel)std::stoi(args[1]);
    }
    catch (const char e) { throw "bad AccessLevel argument"; }

    _login = args[2];
    _password = args[3];
    _name = args[4];
}

//User::User(int id, AccessLevel al, std::string login,
//    std::string password, std::string name)
//{
//    _id = id;
//    _accessLevel = al;
//    _login = login;
//    _password = password;
//    _name = name;
//}

User::~User() {}

Arguments User::arguments() const
{
    return Arguments({
        std::to_string(_id),
        std::to_string((int)_accessLevel),
        _login,
        _password,
        _name
        });
}

User::AccessLevel User::getAccessLevel() const   { return _accessLevel; }

std::string User::getLogin() const               { return _login; }
std::string User::getPassword() const            { return _password; }
                                                 
std::string User::getName() const                { return _name; }