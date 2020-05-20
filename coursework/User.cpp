#include "User.h"

User::User(const Arguments &args)
{
    if (args.size() != 5)
        throw "bad arguments. cant construct user object";

    _id = args[0];
    _accessLevel = (AccessLevel)std::stoi(args[1]);
    _login = args[2];
    _password = args[3];
    _name = args[4];
}

User::~User() {}

Arguments User::convertObject() const
{
    std::string args[5];
    args[0] = _id;
    args[1] = std::to_string((int)_accessLevel);
    args[2] = _login;
    args[3] = _password;
    args[4] = _name;
    
    return Arguments(5, args);
}


User::AccessLevel User::getAccessLevel() const   { return _accessLevel; }

std::string User::getLogin() const               { return _login; }
std::string User::getPassword() const            { return _password; }
                                                 
std::string User::getName() const                { return _name; }