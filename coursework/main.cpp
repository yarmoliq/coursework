#include <iostream>
#include <vector>

//#include "Collection.h"
//#include "User.h" 
//#include "myInput.h"

#include "DataBase.h"

int main()
{
	//User user(Arguments(
	//	{
	//		"888",
	//		"0",
	//		"nuts",
	//		"12345679",
	//		"Den SH."
	//	}
	//));
	//
	//DataBase::getCollection("Users")->add(&user);
	Arguments filter({ "", "", "", "", "Den SH." });
	int res;
	User* user = DataBase::getCollection("Users")->getNext<User>(res,filter);
	 user = DataBase::getCollection("Users")->getNext<User>(res);
	 user = DataBase::getCollection("Users")->getNext<User>(res);
	 user = DataBase::getCollection("Users")->getNext<User>(res);
	 user = DataBase::getCollection("Users")->getNext<User>(res);
	
	delete user;

	return 0;
}