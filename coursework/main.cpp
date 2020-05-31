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
	//		"15694",
	//		"0",
	//		"den4ik",
	//		"12345679",
	//		"Den SH."
	//	}
	//));
	
	//userCollection.add(&user);

	User* user = userCollection.getByUniqueArg<User>("login", 2);
	
	//user->_name = "MY NEW NAME";
	//user->_id = 888;
	
	//userCollection.change(user);
	
	delete user;

	return 0;
}