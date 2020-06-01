#pragma once

#ifndef _SESSION_H_
#define _SESSION_H_

#include <queue>

#include "Space.h"
#include "User.h"

class LoginSpace;
class LogoutSpace;

class Session final
{
	friend LoginSpace;
	friend LogoutSpace;
public:
//protected:
//friend class Spaces;
	// i guess put it somewhere so no one touches it
	Session(Space* startingSpace);// , User* user = NULL);
	~Session();

	void _runSpace(Space* space);

	//void addToQueue(Space* newSpace);

protected:
	User* currentUser;
	//std::queue<Space*> spacesQueue;

	//void popSpace();
public:
	User* getCurrentUser();

	void updateUser(User* user);
};



#endif // !_SESSION_H_