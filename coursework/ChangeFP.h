#pragma once

#ifndef _CHANGEFP_
#define _CHANGEFP_

#include "Space.h"

class ChangeFP final : public Space
{
	virtual void MAIN() override;

	User::AccessLevel _accessLevel = User::AccessLevel::ADMIN;
};



#endif // !_CHANGEFP_