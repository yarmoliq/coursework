#pragma once

#ifndef _INDIVIDUAL_
#define _INDIVIDUAL_

#include "Space.h"

class Individual final : public Space
{
	virtual void MAIN() override;

	User::AccessLevel _accessLevel = User::AccessLevel::GUEST;
};



#endif // !_INDIVIDUAL_