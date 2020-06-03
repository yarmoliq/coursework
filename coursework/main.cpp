#include <iostream>
#include <vector>

#include "Session.h"
#include "MainMenu.h"
#include "Printer.h"
#include "Utilities.h"

#include "DataBase.h"

int main()
{
	Session session(new MainMenu);	

	//DataBase::getCollection("FootballPlayers")->add(&fp);

	//int succ;
	//
	//auto args = Arguments({
	//	"",
	//	"",
	//	"",
	//	"",
	//	"",
	//	"",
	//	"",
	//	""
	//	});
	//
	//auto x = DataBase::getCollection("FootballPlayers")->getNext<FootballPlayer>(succ, args);
	//x = DataBase::getCollection("FootballPlayers")->getNext<FootballPlayer>(succ, args);
	//x = DataBase::getCollection("FootballPlayers")->getNext<FootballPlayer>(succ, args);
	//
	//delete x;

	return 0;
}