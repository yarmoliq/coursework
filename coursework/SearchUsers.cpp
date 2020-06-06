#include "SearchUsers.h"

#include <string>
#include <vector>
#include <conio.h>

#include "Printer.h"
#include "DataBase.h"
#include "User.h"
#include "Utilities.h"
#include "myInput.h"

void SearchUsers::MAIN()
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

	Printer::printLine("1 - Search by login");
	Printer::printLine("2 - Search by name");
	char choice = ' ';

	while(choice != '1' and choice != '2')
		choice = _getch();

	std::vector<const User*> filteredUsers;

	Printer::print(" >> ");
	auto xxx = myInput::Input<std::string>();

	if (choice == '1')
	{
		for (auto& user : users)
			if (utls::toLower(user.getLogin()).find(utls::toLower(xxx)) != std::string::npos)
				filteredUsers.push_back(&user);
	}
	else if (choice == '2')
		{
			for (auto& user : users)
				if (utls::toLower(user.getName()).find(utls::toLower(xxx)) != std::string::npos)
					filteredUsers.push_back(&user);
		}

	if (filteredUsers.size() == 0)
	{
		Printer::printLine("No matching results!");
		return;
	}

	std::vector<unsigned int> buffers = {
		8,
		17,
		15,
		25
	};

	for (const auto& user : filteredUsers)
	{
		// convert player to have only improtant fields (!ID)

		auto converted = Printer::convert(user);
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