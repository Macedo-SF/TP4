#pragma once

#include <iostream>
#include <sstream>
#include <string>

class index
{

public:
	std::string key;
	int pos;
	//std::streamsize bytes;

	index();
	index(char* input);
	index(std::string& input);
	index(char* input, int tell);
	index(std::string input, int tell);
	~index();

	friend std::ostream& operator <<(std::ostream& out, const index& i);
	friend std::istream& operator >>(std::istream& in, const index& i);
	friend bool operator ==(const index& l, const index& r);
};