#pragma once

#ifndef _ARGUMENTS_H_
#define _ARGUMENTS_H_

#include <string>
#include <iostream>
#include <stdexcept>

template<int N>
class Arguments
{
protected:
	std::string arguments[N];
public:
	Arguments(const std::string(&args)[N])
	{
		for (int i = 0; i < N; ++i)
			arguments[i] = args[i];
	}

	std::string operator[](const int i) const
	{
		if (i < 0 or i >= N)
			throw std::out_of_range("Arguments index is out of range!");
		return arguments[i];
	}
};


#endif // !_ARGUMENTS_H_