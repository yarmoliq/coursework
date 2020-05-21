#include <iostream>

#include "Collection.h"
#include "User.h" 
//#include "myInput.h"

int main()
{
	Collection userCollection;

	userCollection.path = "./TESTS/DB/";
	userCollection.name = "Users";

	//User user(Arguments(
	//	{
	//		"91430066",
	//		"2",
	//		"PADLA S POHOJIM ID",
	//		"moi password",
	//		"Sobaka Licaya"
	//	}
	//));

	//userCollection.add(&user);

	auto user = userCollection.getByID<User>("91430066");

	if (user)
	{
		std::cout << "Welcome back, " + user->getName() + "!\n";
	}
	else std::cout << "Create a free account!\n";

	delete user;

	return 0;
}