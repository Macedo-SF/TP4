#include "index.h"

index::index() {
	key = "-"; //* é usado na remoção, trocar um dos
	pos = 0;
	//bytes = 0;
}
index::index(char* input) {
	key = strtok(input, "_");
	pos = std::stoi(strtok(NULL, "_"));
}
index::~index() {
	//
}
index::index(char* input, int tell) {
	std::stringstream s(input);
	std::string temp;

	pos = tell;

	//s.seekg(0, std::ios::end);
	//bytes = s.tellg();

	//s.seekg(0, std::ios::beg);
	getline(s, temp, ';');
	key = temp;
}
index::index(std::string input, int tell) {
	pos = tell;
	key = input;
}

std::ostream& operator <<(std::ostream& out, const index& i) {
	out << i.key << '_' << i.pos;
	return out;
}
std::istream& operator >>(std::istream& in, index& i) {
	in >> i.key;
	in >> i.pos;
	//i.bytes = (1 + i.key.length() + sizeof(i.pos)); //likely wrong
	return in;
}
bool operator ==(const index& l, const index& r) {
	if (l.key == r.key and l.pos == r.pos /*and l.bytes == r.bytes*/) { return true; }
	return false;
}