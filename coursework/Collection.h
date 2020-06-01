#pragma once

#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <vector>
#include <fstream>
#include <string>
#include <direct.h> // _mkdir() 
#include <type_traits>

#include "FileReadWrite.h"
#include "Object.h"
#include "Arguments.h"

class DataBase;

class Collection final
{
public:
	bool add(const Object * const object);
	
	template<class ObjectDerived,
		class = std::enable_if_t<std::is_base_of_v<Object, ObjectDerived>>
	>
	ObjectDerived* getByID(const unsigned int ID)
	{
		Arguments args;
		bool successfulRead = read(ID, args);

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

	template<class ObjectDerived,
		class = std::enable_if_t<std::is_base_of_v<Object, ObjectDerived>>
	>
	ObjectDerived* getByUniqueArg(const std::string& arg, size_t argIndx)
	{
		for (const auto& id : _index)
		{
			Arguments args;
			bool rs = read(id, args);
			if (!rs)
				return NULL;

			if (arg == args[argIndx])
				return new ObjectDerived(args);
		}

		return NULL;
	}

	template<class ObjectDerived,
		class = std::enable_if_t<std::is_base_of_v<Object, ObjectDerived>>
	>
	ObjectDerived* getNext(unsigned int requestedID = UINT_MAX)
	// if requestedID == UINT_MAX the function will return
	// the next element after the last returned element -> lastID + 1
	// if requestedID != UINT_MAX the function will return
	// the next element after requestedID -> requestedID + 1
	{
		if (_index.size() == 0)
			return NULL;

		static unsigned int lastID = _index[_index.size()-1];

		if (requestedID != UINT_MAX)
			lastID = requestedID;

		//auto newID = lastID = getNextID(lastID);
		auto x = getNextID(lastID);

		unsigned int newID;

		if (x != UINT_MAX)
			newID = lastID = x;
		else // ID was not found
			return NULL;

		
		Arguments args;
		bool rs = read(newID, args);
		if (!rs)
			return NULL;

		return new ObjectDerived(args);
	}

	// [add] filter(arguments)

	bool change(const Object* const newObject);

	bool del(const unsigned int ID);

	Collection(std::string path, std::string name);
	~Collection();

protected:
	// reads object data from a corresponding file
	bool read(const unsigned int ID, Arguments& args);
	// writes object data to a corresponding file
	bool write(const Arguments& args);

	unsigned int generateID() const;
	unsigned int getNextID(unsigned int currentID) const;

	std::vector<unsigned int> _index; // stores all IDs
	const std::string _indexFileName = "__INDEX__";

	const std::string name; // must be unique, obviously
	const std::string path; // e.g. "./DataBase/"
	std::string dir() const; // "[path][name]/" // directory for stroring the collection's files

	bool objectExists(const unsigned int ID);
	bool checkUniqueArgs(const std::string& uArgs, const Arguments& newArgs);

	
	// returns true if operation successful
	bool addToIndex(unsigned int ID);
	bool deleteFromIndex(unsigned int ID);

	bool writeIndex();
	bool readIndex();

	friend class DataBase;
};




#endif // !_COLLECTION_H_