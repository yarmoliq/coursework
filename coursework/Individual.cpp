#include "Individual.h"

#include <string>
#include <vector>
#include <conio.h>

#include "Printer.h"
#include "DataBase.h"
#include "FootballPlayer.h"
#include "Utilities.h"

struct Crutch
{
	FootballPlayer* player = NULL;

	unsigned int getGAP() const { return player->getNumberOfGoals() + player->getNumberOfPasses(); }
};

void Individual::MAIN()
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

	std::vector<Crutch> crutch(players.size());
	for (size_t i = 0; i < crutch.size(); i++)
		crutch[i].player = &(players[i]);

	utls::sort(crutch, &Crutch::getGAP, false); // false for descendign order

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

	size_t stop = min(crutch.size(), 6);

	for (size_t i = 0; i < stop; i++)
	{
		auto converted = Printer::convert(crutch[i].player);
		converted.erase(converted.begin()); // deletes ID
		Printer::printObject(converted, '|', buffers, Printer::Alignment::CENTER);
	}
	
}
