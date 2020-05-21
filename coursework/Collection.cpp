#include "Collection.h"


std::string Collection::dir() const { return path + name + "/"; }

//bool Collection::dirExists()
//{
//	std::string dirName_in = "./" + name + "/";
//
//	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
//
//	if (ftyp == INVALID_FILE_ATTRIBUTES)
//		return false;  //something is wrong with your path
//
//	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
//		return true;   // this is a directory
//
//	return false;    // this is not a directory
//}

void Collection::add(const Object* const object)
{
	std::string fileName = object->getID() + ".txt";

	if (FileReadWrite::fileExists(fileName))
		return;
	
	Arguments args = convert(object);

	FileReadWrite::write(dir(), fileName, args);
}

Object* Collection::getByID(const std::string ID)
{
	if (FileReadWrite::dirExists(dir()))
		return NULL;

	std::string fileName = ID + ".txt";

	Arguments args;
	bool successfulRead = FileReadWrite::read(dir(), fileName, &args);

	if(successfulRead)
		return convert(args);

	return NULL;
}

bool Collection::del(const std::string ID)
{
	return false;
}

bool Collection::del(const Object* const object)
{
	return false;
}

bool Collection::change(const std::string ID)
{
	return false;
}

bool Collection::change(const Object* const object)
{
	return false;
}

Collection::Collection()
{
}

Collection::~Collection()
{
}
