#include "PrintUsers.h"

#include <string>
#include <vector>
#include <conio.h>

#include "Printer.h"
#include "DataBase.h"
#include "User.h"
#include "Utilities.h"

void PrintUsers::MAIN()
{
	std::vector<User> users;

	int succ = 1;
	// reading
	while (succ != 2)
	{
		// getting a player. NULL if failed. // succ = 2 if checked all players
		Arguments fake({ "", "", "", "", "", "", "", "" });
		auto user = DataBase::getCollection("Users")->getNext<User>(succ, fake);

		if (user != NULL)
			users.push_back(*user);

		delete user;
	}

	if (users.size() == 0)
	{
		Printer::printLine("No users!");
		return;
	}

	Printer::printLine("Do you want to sort users?");
	Printer::printLine("Yes - 1, No - 2");
	char choice = ' ';

	while (choice != '1' and choice != '2')
		choice = _getch();

	std::vector<std::string> header =
	{
		"ID",
		"Access level",
		"Login",
		"Name"
	};

	if (choice == '1')
	{
		Printer::printLine("Sort by:");
		auto by = Printer::menu(header);

		Printer::printLine("Ascending?");
		Printer::printLine("Yes - 1, No - 2");
		char ascChoice = ' ';

		while (ascChoice != '1' and ascChoice != '2')
			ascChoice = _getch();

		bool ascending = (ascChoice == '1' ? true : false);

		switch (by)
		{
			case 3: {
				utls::sort(users, &User::getName, ascending);
				break;
			}
			case 2: {
				utls::sort(users, &User::getLogin, ascending);
				break;
			}
			case 1: {
				utls::sort(users, &User::getAccessLevel, ascending);
				break;
			}
			case 0: {
				utls::sort(users, &User::getID, ascending);
				break;
			}
			default: {
				break;
			}
		}
	}
	std::vector<unsigned int> buffers =
	{
		8,
		17,
		15,
		25
	};

	int deviderSize = -1;
	for (auto e : buffers)
		deviderSize += e + 1;

	Printer::printObject(header, '|', buffers, Printer::Alignment::CENTER);
	Printer::printLine(std::string(deviderSize, '-'));

	for (const auto& user : users)
	{
		// convert player to have only improtant fields (!ID)

		auto converted = Printer::convert(&user);
		//converted.erase(converted.begin()); // deletes ID
		converted.erase(converted.begin() + 3); // password
		
		if (converted[1] == "0")
			converted[1] = "GUEST";
		if (converted[1] == "1")
			converted[1] = "REGISTERED USER";
		if (converted[1] == "2")
			converted[1] = "MODERATOR";
		if (converted[1] == "3")
			converted[1] = "ADMINISTRATOR";

		Printer::printObject(converted, '|', buffers, Printer::Alignment::CENTER);
	}
}