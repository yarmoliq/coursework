#include "MainMenu.h"

#include <iostream>
#include <conio.h>

#include "LoginSpace.h"
#include "Logout.h"
#include "Register.h"
#include "Printer.h"
#include "AddFP.h"
#include "ViewFP.h"
#include "ChangeUser.h"
#include "ChangeMyInfo.h"
#include "Individual.h"
#include "ChangeFP.h"
#include "PrintUsers.h"

Space* _login() { return new LoginSpace; }
Space* _logout() { return new Logout; }
Space* _register() { return new Register; }
Space* _addFP() { return new AddFP; }
Space* _viewFP() { return new ViewFP; }
Space* _changeUser() { return new ChangeUser; }
Space* _changeFP() { return new ChangeFP; }
Space* _changeMe() { return new ChangeMyInfo; }
Space* _individual() { return new Individual; }
Space* _printUsers() { return new PrintUsers; }

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
				_individual
			};
			labels = {
				"Log in",
				"Register",
				"Best players",

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
				_addFP,
				_changeFP,
				_printUsers,
				_changeUser,
				_changeMe,
				_individual
				};
				labels = {
					"Log out",
					"View players",
					"Add a new player",
					"Change players info",
					"View users",
					"Change user's info",
					"Edit my profile",
					"Best players",

					"Exit"
				};
				break;
			case User::AccessLevel::MODERATOR:
				spaces = {
				_logout,
				_viewFP,
				_changeMe,
				_individual
				};
				labels = {
					"Log out",
					"View players",
					"Edit my profile",
					"Best players",

					"Exit"
				};
				break;
			case User::AccessLevel::REGISTERED_USER:
				spaces = {
				_logout,
				_viewFP,
				_changeMe,
				_individual
				};
				labels = {
					"Log out",
					"View players",
					"Edit my profile",
					"Best players",

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