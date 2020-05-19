#pragma once

#ifndef _ARGUMENTS_H_
#define _ARGUMENTS_H_

#include <string>
#include <iostream>
#include <stdexcept>

class Arguments final
{
public:

	Arguments(const int n, const std::string *const args);
	Arguments(const Arguments &other);
	std::string operator[](const int i) const;
	~Arguments();

private:

	int _argsNumber;
	std::string* _arguments;
	
};


#endif // !_ARGUMENTS_H_
