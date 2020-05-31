#include "FileReadWrite.h"

#include <fstream>
#include <direct.h> // _mkdir()

bool FileReadWrite::dirExists(const std::string& dirName)
{
	DWORD ftyp = GetFileAttributesA(dirName.c_str());

	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

bool FileReadWrite::fileExists(const std::string& fileName)
{
	std::fstream fileStream(fileName);

	bool exists = false;

	if (fileStream.is_open())
		exists = true;

	fileStream.close();
	return exists;
}

bool FileReadWrite::fileExists(const std::string& dirName, const std::string& fileName)
{
	return fileExists(dirName+fileName);
}

bool FileReadWrite::write(const std::string& dir, const std::string& fileName, const Arguments& args)
{
	return write(dir + fileName, args);
}

bool FileReadWrite::read(const std::string& dir, const std::string& fileName, Arguments* const args)
{
	return read(dir+fileName, args);
}

bool FileReadWrite::write(const std::string& fileName, const Arguments& args)
{
	std::ofstream output(fileName);

	if (!output.is_open())
		return false;

	for (int i = 0; i < args.size() - 1; ++i)
		output << args[i] << '\n';

	output << args[args.size() - 1];

	output.close();
	return true;
}

bool FileReadWrite::read(const std::string& fileName, Arguments* const args)
{
	std::ifstream input(fileName);

	if (!input.is_open())
		return false;

	std::vector<std::string> data;

	while (!input.eof())
	{
		std::string line;
		getline(input, line);

		data.push_back(line);
	}

	*args = Arguments(data);

	input.close();
	return true;
}

bool FileReadWrite::deleteFile(const std::string& fileName)
{
	int result = remove(fileName.c_str()); // returns 0 if file was deleted

	if (result == 0)
		return true;

	return false;
}

bool FileReadWrite::deleteFile(const std::string& dir, const std::string& fileName)
{
	return deleteFile(dir + fileName);
}

void FileReadWrite::makeDir(const std::string& dir, const std::string newDirName)
{
	std::string newDir = dir + newDirName;
	_mkdir(newDir.c_str());
}