#include "AddFP.h"

#include <string>

#include "Printer.h"
#include "myInput.h"
#include "Arguments.h"
#include "DataBase.h"

void AddFP::MAIN()
{
	Printer::printLine("---Adding new player---");
	Printer::print("Enter a name: ");
	auto name = myInput::Input<std::string>();

	Printer::print("Enter a birthday: ");
	auto bd = myInput::Input<std::string>();

	Printer::print("Enter a number of matches: ");
	auto matches = myInput::Input<unsigned int>();

	Printer::print("Enter a number of goals: ");
	auto goals = myInput::Input<unsigned int>();

	Printer::print("Enter a number of passes: ");
	auto passes = myInput::Input<unsigned int>();

	Printer::print("Enter a number of yellow cards: ");
	auto yellow = myInput::Input<unsigned int>();

	Printer::print("Enter a number of red cards: ");
	auto red = myInput::Input<unsigned int>();

	FootballPlayer newFP(Arguments({
		"0", // id. sets by collection class
		name,
		bd,
		std::to_string(matches),
		std::to_string(goals),
		std::to_string(passes),
		std::to_string(yellow),
		std::to_string(red)
		}));

	bool succ = DataBase::getCollection("FootballPlayers")->add(&newFP);
	if (succ)
		Printer::printLine("Added successfully!");
	else
		Printer::printLine("There was an error! Try again later.");
}