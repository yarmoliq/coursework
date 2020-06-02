#include <iostream>
#include <vector>

#include "Session.h"
#include "MainMenu.h"
#include "Printer.h"

int main()
{
	//Session session(new MainMenu);

	//Printer::printLine("anton", Printer::CENTER, 30);
	//Printer::print("new line");

	User user(Arguments(
		{
			"15694",
			"0",
			"den4ik",
			"12345679",
			"Den SH."
		}
	));

	std::vector<std::string> params = Printer::convert(&user);
	std::vector<unsigned int> buffers = { 10, 3, 10, 15, 15 };

	Printer::printObject(params,'|', buffers);

	return 0;
}