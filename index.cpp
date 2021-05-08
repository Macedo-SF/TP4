#include "index.h"

index::index() {
	key = "no_key";
	pos = bytes = 0;
}
index::~index() {
	//
}
index::index(char* input, int tell) {
	std::stringstream s(input);
	std::string temp;

	pos = tell;

	s.seekg(0, std::ios::end);
	bytes = s.tellg();

	s.seekg(0, std::ios::beg);
	getline(s, temp, ';');
	key = temp;
}

std::ostream& operator <<(std::ostream& out, const index& i) {
	out << i.key << ';' << i.pos;
	return out;
}
std::istream& operator >>(std::istream& in, index& i) {
	in >> i.key;
	in >> i.pos;
	i.bytes = (1 + i.key.length() + sizeof(i.pos)); //likely wrong
	return in;
}
bool operator ==(const index& l, const index& r) {
	if (l.key == r.key and l.pos == r.pos and l.bytes == r.bytes) { return true; }
	return false;
}