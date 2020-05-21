#pragma once

#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <vector>
#include <string>
#include <direct.h> // _mkdir() 
#include <type_traits>

#include "FileReadWrite.h"
#include "Collection.h"
#include "Object.h"
#include "Arguments.h"

class Collection
{
public:
	void add(const Object * const object);
	// [add] adding a list of objects
	
	template<class ObjectDerived,
		class = std::enable_if_t<std::is_base_of_v<Object, ObjectDerived>>
	>
	ObjectDerived* getByID(const std::string ID)
	{
		if (!FileReadWrite::dirExists(dir()))
			return NULL;

		std::string fileName = ID + ".txt";

		if (!FileReadWrite::fileExists(dir(), fileName))
			return NULL;

		Arguments args;
		bool successfulRead = FileReadWrite::read(dir(), fileName, &args);

		ObjectDerived* obj = NULL;
		if (successfulRead)
		{
			try {
				obj = new ObjectDerived(args);
			}
			catch(const char msg) {}
		}

		return obj;
	}

	// [add] filter(arguments)

	bool change(const std::string ID, const Object* const newObject);
	bool change(const Object* const objectToChange, const Object* const newObject);

	bool del(const std::string ID);
	bool del(const Object* const object);

	Collection();
	virtual ~Collection();

//protected:

	//Arguments convert(const Object* const object) = 0;
	//Object* convert(const Arguments& args) = 0;



	std::string name; // must be unique, obviously
	std::string path; // e.g. "./DataBase/"
	std::string dir() const; // "[path][name]/"

	// static vector<std::string> collectionNames

	//bool dirExists();

	//friend class DataBase
};




#endif // !_COLLECTION_H_