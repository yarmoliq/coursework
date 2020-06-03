#include "ViewFP.h"

#include <string>
#include <vector>
#include <conio.h>

#include "Printer.h"
#include "DataBase.h"
#include "FootballPlayer.h"
#include "Utilities.h"

void ViewFP::MAIN()
{
	std::vector<FootballPlayer> players;

	int succ = 1;
	// reading
	while (succ != 2)
	{
		// getting a player. NULL if failed. // succ = 2 if checked all players
		Arguments fake({ "", "", "", "", "", "", "", "" });
		auto player = DataBase::getCollection("FootballPlayers")->getNext<FootballPlayer>(succ, fake);

		if (player != NULL)
			players.push_back(*player);

		delete player;
	}

	if (players.size() == 0)
	{
		Printer::printLine("No players!");
		return;
	}

	Printer::printLine("Do you want to sort players?");
	Printer::printLine("Yes - 1, No - 2");
	char choice = ' ';

	while(choice != '1' and choice != '2')
		choice = _getch();

	std::vector<std::string> header =
	{
		"Name",
		"Birthday",
		"Matches",
		"Goals",
		"Passes",
		"YC",
		"RC"
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
			case 0:{
				utls::sort(players, &FootballPlayer::getName, ascending);
				break;
			}
			case 1:{
				utls::sort(players, &FootballPlayer::getBirthDay, ascending);
				break;
			}
			case 2:{
				utls::sort(players, &FootballPlayer::getNumberOfMatches, ascending);
				break;
			}
			case 3:{
				utls::sort(players, &FootballPlayer::getNumberOfPasses, ascending);
				break;
			}
			case 4:{
				utls::sort(players, &FootballPlayer::getNumberOfGoals, ascending);
				break;
			}
			case 5:{
				utls::sort(players, &FootballPlayer::getNumberOfYellowCards, ascending);
				break;
			}
			case 6:{
				utls::sort(players, &FootballPlayer::getNumberOfRedCards, ascending);
				break;
			}
			default:
				break;
		}
	}
	std::vector<unsigned int> buffers =
	{
		25,
		15,
		9,
		8,
		7,
		4,
		4
	};

	int deviderSize = -1;
	for (auto e : buffers)
		deviderSize += e + 1;

	Printer::printObject(header, '|', buffers, Printer::Alignment::CENTER);
	Printer::printLine(std::string(deviderSize, '-'));

	for (const auto& player : players)
	{
		// convert player to have only improtant fields (!ID)

		auto converted = Printer::convert(&player);
		converted.erase(converted.begin()); // deletes ID
		Printer::printObject(converted, '|', buffers, Printer::Alignment::CENTER);
	}

}
