#include "BTree.h"
#define tam 3999

using namespace std;

int main() {

	BTree test(2);
	fstream _file;

	_file.open("teste.csv", ios::in);
	if (!_file.is_open()) { exit(-11); }

	char buffer[tam+1];
	_file.getline(buffer, tam);
	/*
	while(!_file.eof()) {
		int tell = _file.tellg();
		_file.getline(buffer, tam);
		index _insert(buffer, tell);
		test.insert(_insert);
	}*/
	
	
	int _c = 0;
	while (_c<12) {
		int tell = _file.tellg();
		_file.getline(buffer, tam);
		index _insert(buffer, tell);
		test.insert(_insert);
		_c++;
	}
	

	//string _to_find = "s7432";
	//cout << test._search(_to_find) << endl;

	test.traverse();
	test._export("test_export.csv");
	cout << endl;
	/*
	while (_c != 0) {
		test.traverse();
		cout << endl;
		test.remove(test._search("s"+to_string(_c)));
		_c--;
	}

	test.traverse();
	cout << endl;
	*/
	return 0;
}
//cadastro(inserir e remover) e consulta do banco de dados por indexa��o em arvore B
//inser��o e remo��o locais /n�o precise reorganizar
//cada p�gina da �rvore com 4KB ou menos
//minimizar o n�mero se seeks

//ler os registros para uma �rvore? <- limite de 4K vai deixar no max 3 ou 4 por nodo, ocupa muito espa�o
//usar os dados na �rvore com um �nico seekg para acessar os registros <- porque exportar um arquivo de indices?