#pragma once

#include "Collection.h"
#include "User.h"

class UserCollection : public Collection // final
{
public:
	UserCollection();
	virtual ~UserCollection();

//protected:
	virtual Object* convert(const Arguments& args) override;
	virtual Arguments convert(const Object* const object) override;
};

