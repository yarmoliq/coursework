#pragma once

#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <vector>
#include <string>

class Collection
{
	std::string name;
	std::string directory;



	void add(std::vector<std::string>);
	void change(std::vector<std::string>);
	std::vector<std::string> read(std::string);
	
	//friend class DataBase
};




#endif // !_COLLECTION_H_