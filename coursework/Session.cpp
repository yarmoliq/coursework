#include "Session.h"

Session::Session(Space* startingSpace)//, User* user)
{
	//spacesQueue.push(startingSpace);
	currentUser = NULL;

	_runSpace(startingSpace);
}

Session::~Session()
{
	delete currentUser;
	//while (!spacesQueue.empty())
	//	popSpace();
}

void Session::_runSpace(Space* space)
{
	space->__currentUser = this->currentUser;
	space->__currentSession = this;

	space->run();

	delete space;
}

User* Session::getCurrentUser()
{
	return currentUser;
}

void Session::updateUser(User* user)
{
	delete currentUser;
	currentUser = user;
}

//void Session::addToQueue(Space* newSpace)
//{
//	spacesQueue.push(newSpace);
//}
//
//void Session::popSpace()
//{
//	delete spacesQueue.front();
//	spacesQueue.pop();
//}
