#pragma once
#ifndef _SEARCHUSERS_
#define _SEARCHUSERS_

#include "Space.h"

class SearchUsers final : public Space
{
	virtual void MAIN() override;

	User::AccessLevel _accessLevel = User::AccessLevel::ADMIN;
};

#endif // !_SEARCHUSERS_