#include "BTree.h"
#include <fstream>
#define tam 3999

using namespace std;

int main() {

	BTree test(3);
	fstream _file;

	_file.open("teste.csv", ios::in);
	if (!_file.is_open()) { exit(-11); }

	char buffer[tam+1];
	_file.getline(buffer, tam);

	while(!_file.eof()) {
		int tell = _file.tellg();
		_file.getline(buffer, tam);
		index _insert(buffer, tell);
		test.insert(_insert);
	}

	string _to_find = "s7643";
	cout << test._search(_to_find) << endl;

	return 0;
}
//cadastro(inserir e remover) e consulta do banco de dados por indexa��o em arvore B
//inser��o e remo��o locais /n�o precise reorganizar
//cada p�gina da �rvore com 4KB ou menos
//minimizar o n�mero se seeks