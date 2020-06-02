#include "Utilities.h"

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
