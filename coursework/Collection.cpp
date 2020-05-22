#include "Collection.h"

std::string Collection::dir() const { return path + name + "/"; }

void Collection::add(const Object* const object)
{
	std::string fileName = std::to_string(object->getID());// +".txt";

	if (FileReadWrite::fileExists(dir(), fileName))
		return;
	
	Arguments args = object->arguments();

	FileReadWrite::write(dir(), fileName, args);
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
		for (int i = 0; i < _index.size() - 1; ++i)
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

	for (int i = 0; i < _index.size(); ++i)
		inputIndex >> _index[i];

	inputIndex.close();
	return true;		
}