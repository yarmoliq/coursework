#pragma once

#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <vector>
#include <string>
#include <windows.h> // DWORD, attributes

#include "Object.h"
#include "Arguments.h"

class Collection // final
{
public:
	void add(const Arguments& args);
	void add(const std::vector<Arguments>& argss);

	
private:
	std::string name; // must be unique, obviously
	std::string dir() const; // "./[name]/"

	// static vector<std::string> collectionNames

	bool dirExists();


	//friend class DataBase
};




#endif // !_COLLECTION_H_