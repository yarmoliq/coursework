#pragma once

#ifndef _ARGUMENTS_H_
#define _ARGUMENTS_H_

#include <string>

template<int N>
class Arguments
{
protected:
	std::string arguments[N];
public:
	Arguments(const std::string(&args)[N]);

	std::string operator[](const int i) const;
};


#endif // !_ARGUMENTS_H_



