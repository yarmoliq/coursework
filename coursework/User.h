#pragma once

#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

#include "Object.h"

class User : public Object
{
public:

	enum class AccessLevel { REGISTERED_USER, MODERATOR, ADMIN };	

	AccessLevel getAccessLevel() const;

	std::string getLogin() const;
	std::string getPassword() const;

	std::string getName() const;

	//virtual std::vector<std::string> convertObject() const;
	
protected:

	AccessLevel _accessLevel;

	std::string _login;
	std::string _password;

	std::string _name;

	
	//User(std::string id, AccessLevel al, std::string login,
	//	std::string password, std::string name);
	User(const std::string (&params)[5]);
	virtual ~User();

	// [todo] friend class ManageUser
};

#endif _USER_H_