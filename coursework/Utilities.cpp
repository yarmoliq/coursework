#include "Utilities.h"

#include <conio.h>

char utls::toLower(char in)
{
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

std::string utls::toLower(std::string in)
{
    for (auto& c : in)
        c = toLower(c);
    return in;
}

std::vector<std::string> utls::toLower(std::vector<std::string> in)
{
    for (auto& s : in)
        s = toLower(s);
    return in;
}

std::string utls::secretInput()
{
	std::string result = "";
	while (true)
	{
		char c = _getch(); // read pressed symbol

		if (c == '\r' and result.length() > 0) // pressed enter
		{
			printf("%c", '\n');
			return result;
		}

		if (c == 8 and result.length() > 0) // pressed backspace
		{
			result.pop_back();

			printf("%c", 13); // start printing in the same line
			printf(std::string(100, ' ').c_str()); // print lots of spaces to "clear" line
			printf("%c", 13); // start printing in the same line
			printf(std::string(result.length(), '*').c_str());
			continue;
		}

		result += c;
		printf("%c", '*');
	}
}
