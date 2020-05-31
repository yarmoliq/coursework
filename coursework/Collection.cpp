#include "Collection.h"

#include <time.h>  

std::string Collection::dir() const { return path + name + "/"; }

bool Collection::add(const Object* const object)
{	
	if (object == NULL)
		return false;

	Arguments args = object->arguments();
	std::string uniqueArgs = object->uniqueArguments();

	if (uniqueArgs != "") // no need to check for other unique arguments
		if (!checkUniqueArgs(uniqueArgs, args)) // we have an element with the same unique arguments
			return false; 

	auto id = generateID();
	std::string fileName = args[0] = std::to_string(id);
	 
	bool ws = FileReadWrite::write(dir(), fileName, args);

	if (!ws)
		return false;

	_index.push_back(id);
	writeIndex();

	return true;
}


Collection::Collection(std::string path, std::string name) : path(path), name(name)
{
	if (!FileReadWrite::dirExists(path))
		throw "Directory doesnt exist :(";
	
	if (!FileReadWrite::dirExists(dir()))
	{
		FileReadWrite::makeDir(path, name);
		_index = {};
		writeIndex();
	}
	else {
		if (!FileReadWrite::fileExists(dir(), _indexFileName))
		{
			_index = {};
			writeIndex();
		}
		else
			readIndex();
	}
}
Collection::~Collection() {}

bool Collection::read(unsigned int id, Arguments& args)
{
	if (!FileReadWrite::dirExists(dir()))
		return NULL;

	std::string fileName = std::to_string(id);// +".txt";

	if (!FileReadWrite::fileExists(dir(), fileName))
		return NULL;

	return FileReadWrite::read(dir(), fileName, &args);
}

unsigned int Collection::generateID() const
{
	// ITS INEFFICIENT BUT I DONT HAVE TIME FOR A BETTER SOLUTION
	unsigned int id;
	while (true)
	{
		bool unique = true;
		srand(time(NULL));
		srand(time(NULL)*rand());
		id = rand();


		for(const auto& realID : _index )
			if (id == realID)
			{
				unique = false;
				break;
			}

		if (unique == false)
			continue;

		break;
	}

	return id;
}

bool Collection::objectExists(unsigned int ID)
{
	for (auto id : _index)
		if (id == ID)
			return true;
	return false;
}

bool Collection::checkUniqueArgs(const std::string& uArgs, const Arguments& newArgs)
{
	std::vector<unsigned int> uniqueArgs;
	for (size_t i = 0; i < uArgs.length(); ++i)
		if (uArgs[i] == '1')
			uniqueArgs.push_back(i+1); // because 0s is ID and we need to check other arguments after ID

	if (uniqueArgs.size() == 0)
		return true;

	for (const auto& id : _index)
	{
		Arguments args;
		bool rs = read(id, args);
		if (!rs) // file was not found. but for some reason we have it in index. shouldve added smth to solve that but i dont have time
			continue;

		for (size_t i = 0; i < uniqueArgs.size(); i++)
			if (args[uniqueArgs[i]] == newArgs[uniqueArgs[i]])
				return false;
	}

	return true;
}

bool Collection::writeIndex()
{
	std::string file = dir() + _indexFileName;
	std::ofstream indexSizeOutput(file + ".size");
	if (!indexSizeOutput.is_open())
		return false;

	indexSizeOutput << _index.size();

	indexSizeOutput.close();


	std::ofstream indexOutput(file);
	if (!indexOutput.is_open())
		return false;

	if (_index.size() != 0)
	{
		for (size_t i = 0; i < _index.size() - 1; ++i)
			indexOutput << _index[i] << '\n';
		indexOutput << _index[_index.size() - 1];
	}

	indexOutput.close();
	return true;
}

bool Collection::readIndex()
{
	std::string file = dir() + _indexFileName;
	std::ifstream inputIndexSize(file + ".size");
	if (!inputIndexSize.is_open())
		return false;

	int indexSize = -1;
	inputIndexSize >> indexSize;
	_index.resize(indexSize);

	inputIndexSize.close();


	if (indexSize == -1) // couldnt read file
		return false;
	if (indexSize == 0) // index is empty -> no need to open it
		return true;


	std::ifstream inputIndex(file);
	if (!inputIndex.is_open())
		return false;

	for (size_t i = 0; i < _index.size(); ++i)
		inputIndex >> _index[i];

	inputIndex.close();
	return true;		
}