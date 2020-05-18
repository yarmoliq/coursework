#pragma once

#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

class User
{
public:

	enum class AccessLevel { REGISTERED_USER, MODERATOR, ADMIN };

	User();
	~User();

	int getID() const;

	std::string getLogin() const;
	std::string getPassword() const;
	std::string getName() const;


	void setID();
	void setLogin();
	void setPassword();
	void setName();


private:

	int _ID;

	std::string _login;
	std::string _password;
	std::string _name;

	static std::vector<const int* const> IDs;

};

class UserManaging
{
	// ?array of IDs
	// check if ID is unique
};

#endif _USER_H_