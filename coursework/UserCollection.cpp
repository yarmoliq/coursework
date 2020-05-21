#include "UserCollection.h"

UserCollection::UserCollection() {}

UserCollection::~UserCollection() {}

Arguments UserCollection::convert(const Object* const object)
{
	Object* nonConstObj = const_cast<Object*>(object);
	User* user = dynamic_cast<User*>(nonConstObj);

	if (user == NULL)
		throw "NOT A USER :(";

	std::string* args = new std::string[5];

	args[0] = user->getID();
	args[1] = std::to_string((int)user->getAccessLevel());
	args[2] = user->getLogin();
	args[3] = user->getPassword();
	args[4] = user->getName();
	
	return Arguments(5, args);
}

Object* UserCollection::convert(const Arguments& args)
{
	if (args.size() != 5)
		return NULL;

	return new User(args);
}