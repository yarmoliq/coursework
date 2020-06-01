#include <iostream>
#include <vector>

#include "Session.h"
#include "MainMenu.h"

int main()
{
	Session session(new MainMenu);

	return 0;
}