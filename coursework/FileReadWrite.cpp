#include "FileReadWrite.h"

#include <fstream>
#include <vector>

//bool FileReadWrite::dirExists(const std::string& dirName_in)
//{
//	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
//
//	if (ftyp == INVALID_FILE_ATTRIBUTES)
//		return false;  //something is wrong with your path!
//
//	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
//		return true;   // this is a directory!
//
//	return false;    // this is not a directory!
//}

bool FileReadWrite::write(std::string dir, std::string fileName, const Arguments& args)
{
	return write(dir + fileName, args);
}

bool FileReadWrite::read(std::string dir, std::string fileName, Arguments* const args)
{
	return read(dir+fileName, args);
}

bool FileReadWrite::write(std::string fileName, const Arguments& args)
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

bool FileReadWrite::read(std::string fileName, Arguments* const args)
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