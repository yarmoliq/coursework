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

	// converts an object into Arguments
	virtual Arguments arguments() const = 0;

	//Object();
	//virtual ~Object();

protected:
	
	unsigned int _id = 0;


	// [todo][not sure, obviously] friend class ?DB
};





#endif // !_OBJECT_H_