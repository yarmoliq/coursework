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

	//User* user = userCollection.getByID<User>(11365);
	//
	//delete user;

	return 0;
}