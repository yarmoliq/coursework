#pragma once

#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

#include "Object.h"
#include "Arguments.h"

class Collection;

class User : public Object // make final
{
public:

	enum class AccessLevel { GUEST, REGISTERED_USER, MODERATOR, ADMIN };	

	User(const Arguments& args);
	virtual ~User();

	Arguments arguments() const override; 
	// mb make protected/private so only DB can access
	// because you can get the password in there	

	AccessLevel getAccessLevel() const;

	std::string getLogin() const;
	std::string getPassword() const; // mb change to "matches password"

	std::string getName() const;

	std::string uniqueArguments() const override;
protected:

	AccessLevel _accessLevel;

	std::string _login;
	std::string _password;

	std::string _name;


	friend class Collection;
	// probably DB. not usermanager
};

#endif _USER_H_