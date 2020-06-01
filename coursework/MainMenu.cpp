#include "MainMenu.h"

#include <iostream>
#include <conio.h>

#include "LoginSpace.h"
#include "Register.h"

void MainMenu::MAIN()
{
	bool exit = false;
	while (!exit)
	{
		printf("1 - login\n");
		printf("2 - register\n");
		printf("3 - look at peepee\n");
		printf("4 - exit\n");

		char pressedButton = _getch();

		switch (pressedButton)
		{
		case '1': {
			runSpace(new LoginSpace);
			break;
		}
		case '2': {
			runSpace(new Register);
			break;
		}
		case '3': {
			if (this->currentUser() == NULL)
				std::cout << "Register for free!\n";
			else
				std::cout << "Hello, " + this->currentUser()->getName() + "! Welcome back!\n";
			break;
		}
		case '4': {
			return;
		}

		default: 
			break;
		}
	}
}