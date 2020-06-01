#pragma once

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <fstream>
#include <vector>
#include <string>

#include "Collection.h"

/// ALL CLASSES USED WITH COLLECTIONS
#include "Object.h"
#include "User.h"
//#include "FootballPlayer.h"

class DataBase
{
	static const std::string dataBasePath;
	static std::vector<Collection> _collections;
public:
	static Collection* getCollection(std::string collectionName);
};


#endif // !_DATABASE_H_