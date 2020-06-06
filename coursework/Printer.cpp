#include "Printer.h"

#include <conio.h>

#include "myInput.h"

std::vector<std::string> Printer::convert(const Object* const obj)
{
	auto args = obj->arguments();

	std::vector<std::string> converted(args.size());

	for (size_t i = 0; i < converted.size(); i++)
		converted[i] = args[i];

	return converted;
}

void Printer::print(const std::string inputString, Printer::Alignment allignment,
	unsigned int holderSize)
{
	if (holderSize <= inputString.length())
	{
		printf(inputString.c_str());
		return;
	}

	unsigned int ll = inputString.length();
	unsigned int bufferSize = holderSize - ll;

	std::string finalString;

	switch (allignment)
	{
		case Printer::LEFT:
		{
			finalString = inputString + std::string(bufferSize, ' ');
			break;
		}
		case Printer::CENTER:
		{
			unsigned int firstBuffer = bufferSize / 2;
			unsigned int secondBuffer = bufferSize - firstBuffer;
			finalString = std::string(firstBuffer, ' ') + inputString + std::string(secondBuffer, ' ');
			break;
		}
		case Printer::RIGHT:
		{
			finalString = std::string(bufferSize, ' ') + inputString;
			break;
		}
		default:
		{
			finalString = inputString;
			break;
		}
	}

	printf(finalString.c_str());
}

void Printer::printLine(const std::string inputString, Printer::Alignment allignment,
	unsigned int holderSize)
{
	Printer::print(inputString, allignment, holderSize);
	printf("\n");
}

void Printer::printObject(const std::vector<std::string>& object,
	char separator,
	std::vector<unsigned int> buffers,
	std::vector<Alignment> alignments)
{
	
	if (buffers.size() != object.size())
	{
		buffers = std::vector<unsigned int>(object.size(), 0);
		//for (size_t i = 0; i < buffers.size(); i++)
		//	buffers[i] = object[i].length();
	}
	if(alignments.size() != object.size())
		alignments = std::vector<Alignment>(object.size(), Printer::LEFT);

	for (size_t i = 0; i < object.size() - 1; i++)
	{
		Printer::print(object[i], alignments[i], buffers[i]);
		auto temp_str = std::string(1, separator);
		printf(temp_str.c_str());
	}
	auto last = object.size() - 1;
	Printer::print(object[last], alignments[last], buffers[last]);

	printf("\n");
}

void Printer::printObject(const std::vector<std::string>& object,
	char separator,
	std::vector<unsigned int> buffers,
	Alignment alignment)
{
	auto alignments = std::vector<Alignment>(object.size(), alignment);
	printObject(object, separator, buffers, alignments);
}

unsigned int Printer::menu(const std::vector<std::string> menuItems)
{
	unsigned int size = menuItems.size();

	for (size_t i = 0; i < size; i++)
	{
		std::string toPrint = std::to_string(i + 1) + " - " + menuItems[i];
		Printer::printLine(toPrint);
	}
	printf(" >> ");

	while (true)
	{
		auto choice = myInput::Input<unsigned int>();

		if (choice >= 1 and choice <= menuItems.size())
			return choice - 1;
	}

	return 0;
}
