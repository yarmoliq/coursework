#include <iostream>
#include <vector>

#include "Collection.h"
#include "User.h" 
//#include "myInput.h"

int main()
{
	Collection userCollection("./TESTS/DB/", "Users");

	User user(Arguments(
		{
			"0",
			"1",
			"sheepang2",
			"good_password",
			"PADLA S TAKIM JE LOGINOM"
		}
	));

	userCollection.add(&user);

	//auto user = userCollection.getByID<User>(91430066);
	//
	//if (user)
	//{
	//	std::cout << "Welcome back, " + user->getName() + "!\n";
	//}
	//else std::cout << "Create a free account!\n";
	//
	//delete user;

	return 0;
}