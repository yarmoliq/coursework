#pragma once

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <vector>
#include <string>

#include "Arguments.h"

class Object
{
public:

	std::string getID() const;

	virtual Arguments convertObject() const = 0;

	Object();
	virtual ~Object();

protected:
	
	std::string _id;


	// [todo][not sure, obviously] friend class [???]
};





#endif // !_OBJECT_H_