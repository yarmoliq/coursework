#pragma once

#include "User.h"

#include <vector>
#include <string>

#include "Arguments.h"
#include "Object.h"

namespace Printer
{
	enum Alignment { LEFT, CENTER, RIGHT };

	extern unsigned int lineSize;

	std::vector<std::string> convert(const Object* const obj);

	void print(const std::string inputString, Printer::Alignment allignment = Printer::LEFT,
		unsigned int holderSize = 0);
	void printLine(const std::string inputString, Printer::Alignment allignment = Printer::LEFT,
		unsigned int holderSize = 0);


	void printObject(const std::vector<std::string>& object,
		char separator,
		std::vector<unsigned int> buffers,
		std::vector<Alignment> alignments);

	void printObject(const std::vector<std::string>& object,
		char separator,
		std::vector<unsigned int> buffers = std::vector<unsigned int>(0),
		Alignment alignment = CENTER);

	unsigned int menu(const std::vector<std::string> menuItems);

	//void printList(const std::vector<std::string>& list, const std::vector<unsigned int>& )
}