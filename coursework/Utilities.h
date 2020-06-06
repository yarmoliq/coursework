#pragma once

#ifndef _UTILITIES_
#define _UTILITIES_

#include <string>
#include <vector>

namespace utls
{
    char toLower(char in);

    std::string toLower(std::string in);

    std::vector<std::string> toLower(std::vector<std::string> in);

	template <typename ElemType, typename MemberType>
	void sort(std::vector<ElemType>& vec, MemberType member, bool ascending = true)
	//void sort(std::vector<ElemType>& vec, MemberType(ElemType::* member)() const, bool ascending = true)
	{
		for (int j = 0; j < vec.size() - 1; ++j)
			for (int i = 0; i < vec.size() - j - 1; ++i)
				if (((vec[i].*member)() < (vec[i + 1].*member)()) ^ ascending)
					std::swap(vec[i], vec[i + 1]);
	}
}


#endif