#include "ChangeFP.h"

#include <conio.h>
#include <string>
#include <vector>

#include "Printer.h"
#include "DataBase.h"
#include "myInput.h"
#include "FootballPlayer.h"

void changeName(FootballPlayer* fp)
{
	Printer::printLine("Enter new name:");
	auto name = myInput::Input<std::string>();

	Arguments oldArgs = fp->arguments();

	Arguments newArgs = Arguments(
		{
			oldArgs[0],
			name,
			oldArgs[2],
			oldArgs[3],
			oldArgs[4],
			oldArgs[5],
			oldArgs[6],
			oldArgs[7]
		}
	);

	delete fp;
	fp = new FootballPlayer(newArgs);

	bool succ = DataBase::getCollection("FootballPlayers")->change(fp);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changeBD(FootballPlayer* fp)
{
	Printer::printLine("Enter new birthday:");
	auto birthday = myInput::Input<std::string>();

	Arguments oldArgs = fp->arguments();

	Arguments newArgs = Arguments(
		{
			oldArgs[0],
			oldArgs[1],
			birthday,
			oldArgs[3],
			oldArgs[4],
			oldArgs[5],
			oldArgs[6],
			oldArgs[7]
		}
	);

	delete fp;
	fp = new FootballPlayer(newArgs);

	bool succ = DataBase::getCollection("FootballPlayers")->change(fp);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changeNOM(FootballPlayer* fp)
{
	Printer::printLine("Enter new number of matches:");
	auto birthday = myInput::Input<unsigned int>();

	Arguments oldArgs = fp->arguments();

	Arguments newArgs = Arguments(
		{
			oldArgs[0],
			oldArgs[1],
			oldArgs[2],
			std::to_string(birthday),
			oldArgs[4],
			oldArgs[5],
			oldArgs[6],
			oldArgs[7]
		}
	);

	delete fp;
	fp = new FootballPlayer(newArgs);

	bool succ = DataBase::getCollection("FootballPlayers")->change(fp);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changeNOG(FootballPlayer* fp)
{
	Printer::printLine("Enter new number of goals:");
	auto goals = myInput::Input<unsigned int>();

	Arguments oldArgs = fp->arguments();

	Arguments newArgs = Arguments(
		{
			oldArgs[0],
			oldArgs[1],
			oldArgs[2],
			oldArgs[3],
			std::to_string(goals),
			oldArgs[5],
			oldArgs[6],
			oldArgs[7]
		}
	);

	delete fp;
	fp = new FootballPlayer(newArgs);

	bool succ = DataBase::getCollection("FootballPlayers")->change(fp);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changeNOP(FootballPlayer* fp)
{
	Printer::printLine("Enter new number of passes:");
	auto passes = myInput::Input<unsigned int>();

	Arguments oldArgs = fp->arguments();

	Arguments newArgs = Arguments(
		{
			oldArgs[0],
			oldArgs[1],
			oldArgs[2],
			oldArgs[3],
			oldArgs[4],
			std::to_string(passes),
			oldArgs[6],
			oldArgs[7]
		}
	);

	delete fp;
	fp = new FootballPlayer(newArgs);

	bool succ = DataBase::getCollection("FootballPlayers")->change(fp);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changeNOYC(FootballPlayer* fp)
{
	Printer::printLine("Enter new number of yellow cards:");
	auto yc = myInput::Input<unsigned int>();

	Arguments oldArgs = fp->arguments();

	Arguments newArgs = Arguments(
		{
			oldArgs[0],
			oldArgs[1],
			oldArgs[2],
			oldArgs[3],
			oldArgs[4],
			oldArgs[5],
			std::to_string(yc),
			oldArgs[7]
		}
	);

	delete fp;
	fp = new FootballPlayer(newArgs);

	bool succ = DataBase::getCollection("FootballPlayers")->change(fp);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void changeNORC(FootballPlayer* fp)
{
	Printer::printLine("Enter new number of red cards:");
	auto rc = myInput::Input<unsigned int>();

	Arguments oldArgs = fp->arguments();

	Arguments newArgs = Arguments(
		{
			oldArgs[0],
			oldArgs[1],
			oldArgs[2],
			oldArgs[3],
			oldArgs[4],
			oldArgs[5],
			oldArgs[6],
			std::to_string(rc)
		}
	);

	delete fp;
	fp = new FootballPlayer(newArgs);

	bool succ = DataBase::getCollection("FootballPlayers")->change(fp);
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void deleteFP(FootballPlayer* fp)
{
	bool succ = DataBase::getCollection("FootballPlayers")->del(fp->getID());
	if (succ)
		Printer::printLine("Success!");
	else
		Printer::printLine("Error! Try again later.");
}

void ChangeFP::MAIN()
{
	Printer::printLine("Enter player's ID to change their info: ");
	unsigned int ID = myInput::Input<unsigned int>();

	auto fp = DataBase::getCollection("FootballPlayers")->getByID<FootballPlayer>(ID);

	while (fp == NULL)
	{
		Printer::printLine("Player was not found.");
		Printer::printLine("Try again - 1, exit - 2");
		char choice = ' ';
		while (choice != '1' and choice != '2')
			choice = _getch();

		if (choice == '2')
			return;
	}

	std::vector<std::string> options =
	{
		"Name",
		"Birthday",
		"Number of matches",
		"Number of goals",
		"Number of passes",
		"Number of yellow cards",
		"Number of red cards"
	};

	unsigned int choice = Printer::menu(options);

	void(*fs[])(FootballPlayer*) = {
		changeName,
		changeBD,
		changeNOM,
		changeNOG,
		changeNOP,
		changeNOYC,
		changeNORC
	};
	fs[choice](fp);

	delete fp;
}