#pragma once

#include <iostream>
#include <sstream>
#include <string>

class index
{

public:
	std::string key;
	int pos;
	std::streamsize bytes;

	index();
	index(char* input, int tell);
	~index();

	friend std::ostream& operator <<(std::ostream& out, const index& i);
	friend std::istream& operator >>(std::istream& in, const index& i);
};