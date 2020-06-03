#pragma once

#ifndef _CHANGEMYINFO_
#define _CHANGEMYINFO_


#include "Space.h"

class ChangeMyInfo final : public Space
{
	virtual void MAIN() override;

	User::AccessLevel _accessLevel = User::AccessLevel::ADMIN;
};



#endif // !_CHANGEMYINFO_