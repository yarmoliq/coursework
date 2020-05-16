#pragma once
#ifndef _MYINPUT_H_
#define _MYINPUT_H_

#include <iostream>
#include <sstream>
#include <type_traits>
#include <string>

using namespace std;

namespace myInput {
	   
	template<class Arithmetic,
		class = enable_if_t< is_arithmetic_v <Arithmetic>>
	>
	Arithmetic Input()
	{
		Arithmetic x;

		do {
			string str;
			getline(cin, str);

			stringstream sstream;
			sstream << str;

			sstream >> x;

			if (sstream.fail())
			{
				cout << "error\n";
				sstream.clear();
			}
			else break;

		} while (true);

		return x;
	}

	template<class String,
		class = enable_if_t< is_same_v<String, string> >
	>
	string Input()
	{
		string x;
		getline(cin, x);

		return x;
	}
}

#endif _MYINPUT_H_