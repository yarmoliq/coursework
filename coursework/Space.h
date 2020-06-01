#pragma once

#ifndef _SPACE_H_
#define _SPACE_H_

#include "User.h"

class Session;

class Space
{
	friend class Session;
	virtual void run();
protected:
	Session* __currentSession;
	// should be private but i need it protected for LOGIN space
	User* __currentUser; // pointers to the user object managed by session

	// defines users with which access level can access this space
	User::AccessLevel _accessLevel = User::AccessLevel::GUEST; 

	// maybe public idk
	User* currentUser();
	void updateSessionUser(User* user);
	const User::AccessLevel getAccessLevel() const;

	void runSpace(Space* space);

	Space();
	~Space();

	virtual void MAIN() = 0;
};


#endif // !_SPACE_H_