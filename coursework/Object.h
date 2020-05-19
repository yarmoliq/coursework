#pragma once

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <vector>
#include <string>

class Object
{
public:

	std::string getID() const;

	virtual std::vector<std::string> convertObject() const = 0;
	//virtual void initializeWith(const  std::vector<std::string>&) = 0;

protected:
	
	std::string _id;

	Object();
	virtual ~Object();

	// [todo][not sure, obviously] friend class [???]
};





#endif // !_OBJECT_H_