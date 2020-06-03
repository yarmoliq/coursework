#include "MainMenu.h"

#include <iostream>
#include <conio.h>

#include "LoginSpace.h"
#include "Logout.h"
#include "Register.h"
#include "Printer.h"
#include "AddFP.h"
#include "ViewFP.h"

Space* _login() { return new LoginSpace; }
Space* _logout() { return new Logout; }
Space* _register() { return new Register; }
Space* _addFP() { return new AddFP; }
Space* _viewFP() { return new ViewFP; }

std::vector<Space* (*)()> spaces; 
std::vector<std::string> labels;

void MainMenu::MAIN()
{
	while (true)
	{
		if (this->currentUser() == NULL)
		{
			spaces = {
				_login,
				_register,
				_viewFP
			};
			labels = {
				"Log in",
				"Register",
				"View players",

				"Exit"
			};
		}
		else
			switch (this->currentUser()->getAccessLevel())
			{
			case User::AccessLevel::ADMIN:
				spaces = {
				_logout,
				_viewFP,
				_addFP
				};
				labels = {
					"Log out",
					"View players",
					"Add a new player",

					"Exit"
				};
				break;
			case User::AccessLevel::MODERATOR:
				spaces = {
				_logout,
				_viewFP
				};
				labels = {
					"Log out",
					"View players",

					"Exit"
				};
				break;
			case User::AccessLevel::REGISTERED_USER:
				spaces = {
				_logout,
				_viewFP
				};
				labels = {
					"Log out",
					"View players",

					"Exit"
				};
				break;
			default:
				printf("MAIN MENU USER ACCESSLEVEL DEFINITION ERROR\n");
				return;
			}

		auto choice = Printer::menu(labels);

		if (choice == labels.size() - 1) // chose "Exit"
			return;

		runSpace(spaces[choice]());
	}
}