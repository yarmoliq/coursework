#pragma once

#ifndef _ARGUMENTS_H_
#define _ARGUMENTS_H_

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

class Arguments final
{
public:

	Arguments(const int n, const std::string *const args);
	Arguments(const std::vector<std::string> &args);
	Arguments(const Arguments &other);
	std::string& operator[](const int i) const;
	Arguments();
	~Arguments();

	int size() const;

	Arguments& operator=(const Arguments& other);

private:

	int _argsNumber;
	std::string* _arguments;
	
};


#endif // !_ARGUMENTS_H_
