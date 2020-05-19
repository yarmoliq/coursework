#include <iostream>

#include "myInput.h"
#include "UserManager.h"

int main()
{
	//std::cout << "works";
	//
	std::string a[5];
	a[0] = "1337";
	a[1] = "1";
	a[2] = "sheepang";
	a[3] = "maximTitan";
	a[4] = "Maxim Yarmolik";

	Arguments args(5, a);

	User u = UserManager::createUser(args);

	cout << u.getID() << endl;
	User::AccessLevel al = u.getAccessLevel();
	cout << u.getLogin() << endl;
	cout << u.getPassword() << endl;
	cout << u.getName() << endl;

	//
	return 0;
}