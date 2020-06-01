#include <iostream>
#include <vector>

//#include "Collection.h"
//#include "User.h" 
//#include "myInput.h"

#include "DataBase.h"

int main()
{
	User user(Arguments(
		{
			"888",
			"0",
			"den4ik",
			"12345679",
			"Den SH."
		}
	));

	DataBase::getCollection("Users")->add(&user);

	//User* user = userCollection.getByUniqueArg<User>("login", 2);
	
	//delete user;

	return 0;
}