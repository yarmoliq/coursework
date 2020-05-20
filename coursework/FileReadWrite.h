#pragma once

#ifndef _READWRITEFILE_H_
#define _READWRITEFILE_H_

#include <string>

#include "Arguments.h"

class FileReadWrite
{
public:
	static bool write(std::string dir, std::string fileName, const Arguments& args);
	static bool read(std::string dir, std::string fileName, Arguments* const args);
	static bool write(std::string fileName, const Arguments& args);
	static bool read(std::string fileName, Arguments* const args);
private:
	static bool dirExists(const std::string& dirName_in);
};



#endif // !_READWRITEFILE_H_