#include "Collection.h"

std::string Collection::dir() const { return path + name + "/"; }

void Collection::add(const Object* const object)
{
	std::string fileName = std::to_string(object->getID()) + ".txt";

	if (FileReadWrite::fileExists(dir(), fileName))
		return;
	
	Arguments args = object->arguments();

	FileReadWrite::write(dir(), fileName, args);
}




Collection::Collection() {}
Collection::~Collection() {}