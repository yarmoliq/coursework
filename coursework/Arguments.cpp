#include "Arguments.h"

Arguments::Arguments(const int n, const std::string* const args)
{
	_argsNumber = n;
	_arguments = new std::string[n];

	for (int i = 0; i < n; ++i)
		_arguments[i] = args[i];
}

Arguments::Arguments(const std::vector<std::string>& args)
{
	_argsNumber = args.size();
	_arguments = new std::string[_argsNumber];

	for (int i = 0; i < _argsNumber; ++i)
		_arguments[i] = args[i];
}

Arguments::Arguments(const Arguments& other)
{
	_argsNumber = other._argsNumber;
	_arguments = new std::string[_argsNumber];

	for (int i = 0; i < _argsNumber; ++i)
		_arguments[i] = other._arguments[i];
}

std::string Arguments::operator[](const int i) const
{
	if (_argsNumber == 0)
		throw "no elements";
	if (i < 0 or i >= _argsNumber)
		throw std::out_of_range("Arguments index is out of range!");

	return _arguments[i];
}

Arguments::Arguments()
{
	_argsNumber = 0;
	_arguments = NULL;
}

Arguments::~Arguments()
{
	_argsNumber = 0;
	delete[] _arguments;
	_arguments = NULL;
}

int Arguments::size() const { return _argsNumber; }

Arguments& Arguments::operator=(const Arguments& other)
{
	if (this != &other)
	{
		delete[] _arguments;

		_argsNumber = other._argsNumber;
		_arguments = new std::string[_argsNumber];

		for (int i = 0; i < _argsNumber; ++i)
			_arguments[i] = other._arguments[i];
	}
	return *this;
}
