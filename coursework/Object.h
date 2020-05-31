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

	// uniqueArguments indicates whether we need to to
	// have some object properties unique
	// format: "011010"
	// 0 if we dont need a property to be unique, 1 - need
	// first symbol is responsible for the second property
	// because the first property is ID
	virtual std::string uniqueArguments() const;

	bool operator==(const Object& other);

//protected:
	
	// converts an object into Arguments
	virtual Arguments arguments() const = 0;

	unsigned int _id = 0;

	// [todo][not sure, obviously] friend class ?DB
	friend class Collection;
};





#endif // !_OBJECT_H_