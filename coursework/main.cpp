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

	User* user = DataBase::getCollection("Users")->getNext<User>(18661);
	 user = DataBase::getCollection("Users")->getNext<User>();
	 user = DataBase::getCollection("Users")->getNext<User>();
	 user = DataBase::getCollection("Users")->getNext<User>();
	 user = DataBase::getCollection("Users")->getNext<User>();
	
	delete user;

	return 0;
}