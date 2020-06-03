#pragma once

#ifndef _FOOTBALLPLAYER_
#define _FOOTBALLPLAYER_

#include <string>

#include "Object.h"
#include "Arguments.h"

class FootballPlayer final : public Object
{
public:
	FootballPlayer(const Arguments& args);
	virtual Arguments arguments() const override;

	std::string getName() const;
	std::string getBirthDay() const;
	unsigned int getNumberOfMatches() const;
	unsigned int getNumberOfGoals() const;
	unsigned int getNumberOfPasses() const;
	unsigned int getNumberOfYellowCards() const;
	unsigned int getNumberOfRedCards() const;

private:
	std::string name;
	std::string birthDay;
	unsigned int numberOfMatches;
	unsigned int numberOfGoals;
	unsigned int numberOfPasses;
	unsigned int numberOfYellowCards;
	unsigned int numberOfRedCards;
};



#endif // !_FOOTBALLPLAYER_