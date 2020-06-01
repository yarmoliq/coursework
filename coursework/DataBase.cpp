#include "DataBase.h"

const std::string DataBase::dataBasePath = "./DATABASE/";

std::vector<Collection> DataBase::_collections =
{
	Collection(dataBasePath, "Users"),
	Collection(dataBasePath, "FootballPlayers")
};

Collection* DataBase::getCollection(std::string collectionName)
{
	for (auto& collection : _collections)
		if (collection.name == collectionName)
			return &collection;

	return NULL;
}