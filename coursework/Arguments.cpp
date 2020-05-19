#include "Arguments.h"

#include <stdexcept>

template<int N>
Arguments<N>::Arguments(const std::string(&args)[N])
{
	for (int i = 0; i < N; ++i)
		arguments[i] = args[i];
}

template<int N>
std::string Arguments<N>::operator[](const int i) const
{
	if (i < 0 or i >= N)
		throw std::out_of_range("Arguments index is out of range!");
	return arguments[i];
}