#pragma once

#ifndef _READWRITEFILE_H_
#define _READWRITEFILE_H_

#include <string>
#include <windows.h> // DWORD, attributes
#include <stdio.h> // remove()

#include "Arguments.h"

class FileReadWrite final
{
public:
	static bool dirExists(const std::string& dirName);
	static bool fileExists(const std::string& fileName);

	// returns true if operatoin was successful

	// dir format: "./folderName/"
	static bool write(std::string dir, std::string fileName, const Arguments& args);
	static bool read(std::string dir, std::string fileName, Arguments* const args);
	static bool write(std::string fileName, const Arguments& args);
	static bool read(std::string fileName, Arguments* const args);

	// returns true if operatoin was successful
	static bool deleteFile(const std::string& fileName);
private:
};



#endif // !_READWRITEFILE_H_