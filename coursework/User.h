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

	User(const Arguments& args);
	virtual ~User();

	virtual Arguments convertObject() const override;
	

	AccessLevel getAccessLevel() const;

	std::string getLogin() const;
	std::string getPassword() const;

	std::string getName() const;
	
protected:

	AccessLevel _accessLevel;

	std::string _login;
	std::string _password;

	std::string _name;



	//friend class UserManager;
	// probably DB. not usermanager
};

#endif _USER_H_