#include <iostream>

#include "myInput.h"

#include "UserCollection.h"

int main()
{
	// writing test

	//std::string a[5];
	//a[0] = "228";
	//a[1] = "1";
	//a[2] = "yarmoliq";
	//a[3] = "maximTitan";
	//a[4] = "Maxim Yarmolik";
	//Arguments args(5, a);
	//User newuser(args);
	//
	//cout << FileReadWrite::write("./DB/",a[0]+".txt", newuser.convertObject());


	// reading test

	//Arguments args;
	//
	//cout << FileReadWrite::read(". nj/DB/", "228.txt", &args) << endl;
	//
	//try {
	//	User u(args);
	//	//cout << u.get
	//}
	//catch (const char* msg) { cout << msg; }

	Collection* c = new UserCollection();

	c->name = "users-test";

	//vector<string> x{ "1778", "1", "someones-login", "thisISpassword", "Sobaka Licaya" };
	//
	//User user = User(x);

	User* user = dynamic_cast<User*>(c->getByID("1778"));

	true;

	return 0;
}