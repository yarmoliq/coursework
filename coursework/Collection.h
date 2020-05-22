#pragma once

#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <vector>
#include <fstream>
#include <string>
#include <direct.h> // _mkdir() 
#include <type_traits>

#include "FileReadWrite.h"
#include "Collection.h"
#include "Object.h"
#include "Arguments.h"

class Collection // final
{
public:
	void add(const Object * const object); // [todo][not sure] make not void for detecting errors
	// [add] adding a list of objects
	
	template<class ObjectDerived,
		class = std::enable_if_t<std::is_base_of_v<Object, ObjectDerived>>
	>
	ObjectDerived* getByID(const int ID)
	{
		if (!FileReadWrite::dirExists(dir()))
			return NULL;

		std::string fileName = std::to_string(ID);// +".txt";

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

	bool change(const int ID, const Object* const newObject);
	bool change(const Object* const objectToChange, const Object* const newObject);

	bool del(const std::string ID);
	bool del(const Object* const object);

	Collection(std::string path, std::string name);
	virtual ~Collection(); // [todo] remove "virtual" if class is final

//protected:

	std::vector<int> _index; // stores all IDs
	const std::string _indexFileName = "__INDEX__";

	const std::string name; // must be unique, obviously
	const std::string path; // e.g. "./DataBase/"
	std::string dir() const; // "[path][name]/" // directory for stroring the collection's files

	// static vector<std::string> collectionNames

	// array of freed IDs ( if someone deletes their account we can reuse their ID )

	// returns true if operation successful
	bool writeIndex();
	bool readIndex();

	//bool dirExists();
	//friend class DataBase
};




#endif // !_COLLECTION_H_