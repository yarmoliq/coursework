#include "Register.h"

#include <string>

#include "DataBase.h"
#include "myInput.h"

void Register::MAIN()
{
	printf("Enter your name: ");
	auto name = myInput::Input<std::string>();

	printf("Enter login: ");
	auto login = myInput::Input<std::string>();

	User* getUser = DataBase::getCollection("Users")->getByUniqueArg<User>(login, 2);

	while(getUser != NULL)
	{
		printf("The login is already taken. Try another one.\n");
		printf("Enter login:");
		login = myInput::Input<std::string>();
		getUser = DataBase::getCollection("Users")->getByUniqueArg<User>(login, 2);
	}

	printf("Enter password: ");
	auto password = myInput::Input<std::string>();

	User newUser(Arguments({
		"0", "1", login, password, name
		})
	);

	bool result = DataBase::getCollection("Users")->add(&newUser);
	if (!result)
		printf("There was some error. Registration failed. Try again later.\n");

	delete getUser;
}
