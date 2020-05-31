#pragma once

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <vector>
#include <string>

#include "Arguments.h"

class Object
{
public:

	unsigned int getID() const;

	// 1 for each argument after 1st(ID) if needed unique, otherwise 0
	// e.g. i want users to have unique logins -> make this string = "1000"
	// because login is the first argument after ID. other arguments dont 
	// need to be unique -> 0s
	virtual std::string uniqueArguments() const;

	bool operator==(const Object& other);

protected:
	
	// converts an object into Arguments
	virtual Arguments arguments() const = 0;

	unsigned int _id = 0;

	// [todo][not sure, obviously] friend class ?DB
	friend class Collection;
};





#endif // !_OBJECT_H_