#pragma once

#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <vector>
#include <string>
#include <windows.h> // DWORD, attributes

#include "Object.h"
#include "Arguments.h"

class Collection
{
public:
	void add(const Object * const object);
	void add(const std::vector<const Object*> &objects);
	
	Object* getByID(const std::string ID);
	// filter
	bool del(const std::string ID);
	bool del(const Object* const object);
	bool change(const std::string ID);
	bool change(const Object* const object);

	Collection();
	virtual ~Collection();

//protected:

	virtual Object* convert(const Arguments& args) = 0;
	virtual Arguments convert(const Object* const object) = 0;

	std::string name; // must be unique, obviously
	std::string dir() const; // "./[name]/"

	// static vector<std::string> collectionNames

	bool dirExists();

	//friend class DataBase
};




#endif // !_COLLECTION_H_