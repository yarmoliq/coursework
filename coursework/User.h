#pragma once

#ifndef _USER_H_
#define _USER_H_

#include <string>
//#include <vector>

class User
{
public:

	enum class AccessLevel { REGISTERED_USER, MODERATOR, ADMIN };

	User(std::string, AccessLevel, std::string,
		 std::string, std::string);

	~User();


	std::string getID() const;

	AccessLevel getAccessLevel() const;

	std::string getLogin() const;
	std::string getPassword() const;

	std::string getName() const;


	// [not sure][todo] can be changed only from DB
	//void setID(std::string); // delete
	//void setAccessLevel(AccessLevel);
	//void setLogin(std::string);
	//void setPassword(std::string);
	//void setName(std::string);

private:
	// // [not sure][todo] all this things under should be const
	std::string _ID;

	AccessLevel _accessLevel;

	std::string _login;
	std::string _password;

	std::string _name;
	

	// [not sure][todo] friend class DB // nah. only manager
	// [not sure][todo] friend class ManageUser
};

#endif _USER_H_