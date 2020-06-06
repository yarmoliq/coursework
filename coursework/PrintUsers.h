#pragma once
#ifndef _PRINTUSERS_
#define _PRINTUSERS_

#include "Space.h"

class PrintUsers final : public Space
{
	virtual void MAIN() override;

	User::AccessLevel _accessLevel = User::AccessLevel::ADMIN;
};

#endif // !_PRINTUSERS_