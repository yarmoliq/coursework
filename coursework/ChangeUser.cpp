#include "ChangeUser.h"

#include <conio.h>
#include <string>
#include <vector>

#include "Printer.h"
#include "DataBase.h"
#include "myInput.h"

void changeRole(User* user)
{
	unsigned int newRole = Printer::menu({
		"Registered user",
		"Moderator",
		"Admin"
		});

	Arguments newArgs = Arguments(
		{
			std::to_string(user->getID()),
			std::to_string(newRole + 1),
			user->getLogin(),
			user->getPassword(),
			user->getName()
		}
	);

	delete user;
	user = new User(newArgs);

	bool succ = DataBase::getCollection("Users")->change(user);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changeName(User* user)
{
	Printer::printLine("Enter new name:");
	auto name = myInput::Input<std::string>();

	Arguments newArgs = Arguments(
		{
			std::to_string(user->getID()),
			std::to_string((int)user->getAccessLevel()),
			user->getLogin(),
			user->getPassword(),
			name
		}
	);

	delete user;
	user = new User(newArgs);

	bool succ = DataBase::getCollection("Users")->change(user);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changePassword(User* user)
{
	Printer::printLine("Enter new password:");
	auto name = myInput::Input<std::string>();

	Arguments newArgs = Arguments(
		{
			std::to_string(user->getID()),
			std::to_string((int)user->getAccessLevel()),
			user->getLogin(),
			user->getPassword(),
			name
		}
	);

	delete user;
	user = new User(newArgs);

	bool succ = DataBase::getCollection("Users")->change(user);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void deleteUser(User* user)
{
	bool succ = DataBase::getCollection("Users")->del(user->getID());
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void ChangeUser::MAIN()
{
	Printer::printLine("Enter user's ID to change their info: ");
	unsigned int ID = myInput::Input<unsigned int>();

	auto user = DataBase::getCollection("Users")->getByID<User>(ID);

	while (user == NULL)
	{
		Printer::printLine("User was not found.");
		Printer::printLine("Try again - 1, exit - 2");
		char choice = ' ';
		while (choice != '1' and choice != '2')
			choice = _getch();

		if (choice == '2')
			return;
	}

	std::vector<std::string> options =
	{
		"Role",
		"Name",
		"Password",
		"Delete"
	};

	unsigned int choice = Printer::menu(options);

	void(*fs[])(User*) = {
		changeRole,
		changeName,
		changePassword,
		deleteUser
	};
	fs[choice](user);

	delete user;
}
