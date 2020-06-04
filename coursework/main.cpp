#include <iostream>
#include <vector>

#include "Session.h"
#include "MainMenu.h"
#include "Printer.h"
#include "Utilities.h"

#include "DataBase.h"

int main()
{
	Session session(new MainMenu);	

	return 0;
}