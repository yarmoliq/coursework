#include "Space.h"

#include "Session.h""

void Space::run()
{
	User::AccessLevel alOfUser;

	if (this->__currentUser == NULL)
		alOfUser = User::AccessLevel::GUEST;
	else
		alOfUser = this->__currentUser->getAccessLevel();

	if(alOfUser < _accessLevel)
	{
		printf("[ACCESS DENIED]\n");
		return;
	}

	this->MAIN();
}

User* Space::currentUser() { return __currentSession->getCurrentUser(); }

void Space::updateSessionUser(User* user)
{
	this->__currentSession->updateUser(user);
}

const User::AccessLevel Space::getAccessLevel() const { return this->_accessLevel; }

void Space::runSpace(Space* space)
{
	__currentSession->_runSpace(space);
}


Space::Space()
{
	__currentSession = NULL;
	__currentUser = NULL;
}

Space::~Space() {}
