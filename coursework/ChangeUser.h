#pragma once

#ifndef _CHANGEUSER_
#define _CHANGEUSER_

#include "Space.h"

class ChangeUser final : public Space
{
	virtual void MAIN() override;

	User::AccessLevel _accessLevel = User::AccessLevel::ADMIN;
};


#endif