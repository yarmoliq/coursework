#include "FootballPlayer.h"

FootballPlayer::FootballPlayer(const Arguments& args)
{
    if (args.size() != 8)
        throw "wrong arguments";

    try {
        _id = std::stol(args[0]);
    }
    catch (const char* e) { throw "bad id argument"; }

    name = args[1];
    birthDay = args[2];

    try {
        numberOfMatches = std::stoi(args[3]);
    }
    catch (const char* e) { throw "bad numberOfMatches argument"; }
    try {
        numberOfGoals = std::stoi(args[4]);
    }
    catch (const char* e) { throw "bad numberOfGoals argument"; }
    try {
        numberOfPasses = std::stoi(args[5]);
    }
    catch (const char* e) { throw "bad numberOfPasses argument"; }
    try {
        numberOfYellowCards = std::stoi(args[6]);
    }
    catch (const char* e) { throw "bad numberOfYellowCards argument"; }
    try {
        numberOfRedCards = std::stoi(args[7]);
    }
    catch (const char* e) { throw "bad numberOfRedCards argument"; }
}

Arguments FootballPlayer::arguments() const
{
	return Arguments({
		std::to_string(_id),
		name,
		birthDay,
		std::to_string(numberOfMatches),
		std::to_string(numberOfGoals),
		std::to_string(numberOfPasses),
		std::to_string(numberOfYellowCards),
		std::to_string(numberOfRedCards)
		});
}

std::string FootballPlayer::getName() const
{
    return name;
}

std::string FootballPlayer::getBirthDay() const
{
    return birthDay;
}

unsigned int FootballPlayer::getNumberOfMatches() const
{
    return numberOfMatches;
}

unsigned int FootballPlayer::getNumberOfGoals() const
{
    return numberOfGoals;
}

unsigned int FootballPlayer::getNumberOfPasses() const
{
    return numberOfPasses;
}

unsigned int FootballPlayer::getNumberOfYellowCards() const
{
    return numberOfYellowCards;
}

unsigned int FootballPlayer::getNumberOfRedCards() const
{
    return numberOfRedCards;
}
