#pragma once

#ifndef _ADDFP_
#define _ADDFP_


#include "Space.h"
#include "FootballPlayer.h"

class AddFP final : public Space
{
	virtual void MAIN() override;
	User::AccessLevel _accessLevel = User::AccessLevel::ADMIN;
};



#endif // !_ADDFP_