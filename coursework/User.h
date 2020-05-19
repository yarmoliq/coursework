#pragma once

#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

#include "Object.h"
#include "Arguments.h"

class User : public Object
{
public:

	enum class AccessLevel { REGISTERED_USER, MODERATOR, ADMIN };	

	AccessLevel getAccessLevel() const;

	std::string getLogin() const;
	std::string getPassword() const;

	std::string getName() const;

	virtual Arguments convertObject() const;
	
	virtual ~User();
	
protected:

	AccessLevel _accessLevel;

	std::string _login;
	std::string _password;

	std::string _name;

	User(const Arguments& args);

	// [todo] friend class ManageUser
	friend class UserManager;
};

#endif _USER_H_