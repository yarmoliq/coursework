#pragma once

#ifndef _READWRITEFILE_H_
#define _READWRITEFILE_H_

#include <string>
#include <vector>
#include <windows.h> // DWORD, attributes
#include <stdio.h> // remove()

#include "Arguments.h"

class FileReadWrite final
{
	// returns true if operatoin was successful
public:
	static bool dirExists(const std::string& dirName);
	static bool fileExists(const std::string& fileName);
	static bool fileExists(const std::string& dirName, const std::string& fileName);

	// dir format: "./folderName/"
	static bool write(const std::string& dir, const std::string &fileName, const Arguments& args);
	static bool read(const std::string& dir, const std::string& fileName, Arguments* const args);
	static bool write(const std::string& fileName, const Arguments& args);
	static bool read(const std::string& fileName, Arguments* const args);


	static bool deleteFile(const std::string& fileName);

	static void makeDir(const std::string& dir, const std::string newDirName);
};



#endif // !_READWRITEFILE_H_