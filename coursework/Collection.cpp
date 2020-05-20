#include "Collection.h"

#include <direct.h> // _mkdir()

std::string Collection::dir() const { return "./" + name + "/"; }

bool Collection::dirExists()
{
	std::string dirName_in = "./" + name + "/";

	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());

	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory

	return false;    // this is not a directory
}
