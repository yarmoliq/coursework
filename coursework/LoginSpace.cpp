#include "LoginSpace.h"

//#include <iostream>
#include <string>
#include <conio.h>

#include "DataBase.h"
#include "myInput.h"
//#include "Session.h"

void LoginSpace::MAIN()
{
	if (this->__currentUser != NULL)
	{
		printf("You are already logged in. How did you even get on this page?\n");
		return;
	}

	printf("Enter your login: ");
	auto login = myInput::Input<string>();

	User* user = DataBase::getCollection("Users")->getByUniqueArg<User>(login, 2);

	while (user == NULL)
	{
		printf("User with this login was not found.\n");
		printf("Try again or create an account.\n");
		printf("1 - try again\n");
		printf("2 - back\n");

		char pressedButton = _getch();
		while(pressedButton != '1' and pressedButton != '2')
			pressedButton = _getch();

		if (pressedButton == 2)
			return;

		printf("Enter your login: ");
		login = myInput::Input<string>();
		user = DataBase::getCollection("Users")->getByUniqueArg<User>(login, 2);
	}

	printf("Enter your password: ");
	auto password = myInput::Input<std::string>();

	while (user->getPassword() != password)
	{
		printf("Wrong password.\n");
		printf("Try again or reset password.\n");
		printf("1 - try again\n");
		printf("2 - reset\n");
		printf("(NO RESET FUNCTIONALITY YET)\n");
		printf("3 - back\n");

		char pressedButton = _getch();
		while (pressedButton != '1' and pressedButton != '2' and pressedButton != '3')
			pressedButton = _getch();

		if (pressedButton == 3)
			return;

		printf("Enter your password: ");
		password = myInput::Input<std::string>();
	}

	//update session's current user
	this->updateSessionUser(user);
}
