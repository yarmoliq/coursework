#include <iostream>
#include <vector>

#include "Collection.h"
#include "User.h" 
//#include "myInput.h"

int main()
{
	Collection userCollection("./TESTS/DB/", "Users");

	//User user(Arguments(
	//	{
	//		"0",
	//		"0",
	//		"sobaka",
	//		"pass",
	//		"Antonio Papos"
	//	}
	//));
	//
	//userCollection.add(&user);

	//User* user = userCollection.getByID<User>(22886);
	//
	//user->_name = "MY NEW NAME";
	//user->_id = 888;
	//
	//userCollection.change(user);
	//
	//delete user;

	return 0;
}