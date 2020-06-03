#include "ChangeMyInfo.h"

#include <string>
#include <conio.h>
#include <vector>

#include "Printer.h"
#include "Arguments.h"
#include "myInput.h"
#include "DataBase.h"

void ChangeMyInfo::MAIN()
{
	std::vector<std::string> options =
	{
		"Name",
		"Password",

		"Exit"
	};

	auto choice = Printer::menu(
		options
	);

	if (choice == options.size() - 1)
		return;

	User* newUser = NULL;

	if (choice == 0)
	{
		Printer::print("Enter new name:");
		auto name = myInput::Input<std::string>();

		Arguments newArgs(
			{
				std::to_string( currentUser()->getID()),
				std::to_string( (int)currentUser()->getAccessLevel()),
				currentUser()->getLogin(),
				currentUser()->getPassword(),
				name
			}
		);

		newUser = new User(newArgs);
	}
	else
	{
		Printer::print("Enter new password:");
		auto password = myInput::Input<std::string>();

		Arguments newArgs(
			{
				std::to_string(currentUser()->getID()),
				std::to_string((int)currentUser()->getAccessLevel()),
				currentUser()->getLogin(),
				password,
				currentUser()->getName()
			}
		);

		newUser = new User(newArgs);
	}

	if (newUser == NULL)
	{
		Printer::printLine("Some error! Try again later or idk.");
		return;
	}

	Printer::print("Enter your current password to confirm changes:");
	auto currentPassword = myInput::Input<std::string>();

	if (currentPassword == this->currentUser()->getPassword())
	{
		bool succ = DataBase::getCollection("Users")->change(newUser);
		if (succ)
		{
			this->updateSessionUser(newUser);
			Printer::printLine("Success!");
		}
		else
			Printer::printLine("Some error idk! Try again later or make sure you typed everything right.");
	}
	else
		Printer::printLine("Wrong!!!!");
}
