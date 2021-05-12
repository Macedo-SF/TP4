#include "BTree.h"
#include "feature.h"

using namespace std;

int menu();
void addToFile(string& filename);
index removeFromFile(string& filename, const int& pos);

int main() {
	//navigation
	int option;
	string filename = "teste.csv";
	//a tree for each column to be indexed
	BTree idTree(133); //max index size for the current file is 15B, up to 266 indexes per page
	BTree typeTree(125); //max index size for the current file is 16B, up to 250 indexes per page
	BTree titleTree(20);
	BTree directorTree(30);
	BTree castTree(10);
	BTree countryTree(20);
	BTree yearTree(166);
	BTree delID(133);

	//indexing each to it's own tree
	idTree._index(filename, "id");
	typeTree._index(filename, "type");
	titleTree._index(filename, "title");
	directorTree._index(filename, "director");
	castTree._index(filename, "cast");
	countryTree._index(filename, "country");
	yearTree._index(filename, "year");

	//menu
	while (true) {
		cout << "MENU" << endl << endl;
		cout << "1. Inserir novo feature" << endl;
		cout << "2. Pesquisar catalogo por ID" << endl;
		cout << "3. Pesquisar catalogo por tipo" << endl;
		cout << "4. Pesquisar catalogo por título" << endl;
		cout << "5. Pesquisar catalogo por diretor" << endl;
		cout << "6. Pesquisar catalogo por elenco" << endl;
		cout << "7. Pesquisar catalogo por pais" << endl;
		cout << "8. Pesquisar catalogo por ano" << endl;
		cout << "9. Remover feature" << endl;
		cout << "0. Sair" << endl << endl;

		cout << "Digite a opcao desejada: " << endl;
		cin >> option;
		cin.ignore();

		if (option == 1) {
			system("cls");

			//criar um feature e atualizar cada árvore

			system("pause");
			system("cls");
		}
		else if (option == 2) {
			system("cls");
			
			string to_find;
			cout << "Procurar por: ";
			cin >> to_find;
			//pesquisar na árvore de ID, criar o feature a partir do arquivo
			vector<index> found = idTree._find(to_find);

			cout << endl << found.size() <<" resultados encontrados" << endl;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);
			for (index i : found) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				f.print();
			}

			system("pause");
			system("cls");
		}
		else if (option == 3) {
			system("cls");

			string to_find;
			cout << "Procurar por: ";
			cin >> to_find;
			//pesquisar na árvore de ID, criar o feature a partir do arquivo
			vector<index> found = typeTree._find(to_find);

			cout << endl << found.size() << " resultados encontrados" << endl;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);
			for (index i : found) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				f.print();
			}

			system("pause");
			system("cls");
		}
		else if (option == 4) {
			system("cls");

			string to_find;
			cout << "Procurar por: ";
			cin >> to_find;
			//pesquisar na árvore de ID, criar o feature a partir do arquivo
			vector<index> found = titleTree._find(to_find);

			cout << endl << found.size() << " resultados encontrados" << endl;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);
			for (index i : found) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				f.print();
			}

			system("pause");
			system("cls");
		}
		else if (option == 5) {
			system("cls");

			string to_find;
			cout << "Procurar por: ";
			cin >> to_find;
			//pesquisar na árvore de ID, criar o feature a partir do arquivo
			vector<index> found = directorTree._find(to_find);

			cout << endl << found.size() << " resultados encontrados" << endl;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);
			for (index i : found) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				f.print();
			}

			system("pause");
			system("cls");
		}
		else if (option == 6) {
			system("cls");

			string to_find;
			cout << "Procurar por: ";
			cin >> to_find;
			//pesquisar na árvore de ID, criar o feature a partir do arquivo
			vector<index> found = castTree._find(to_find);

			cout << endl << found.size() << " resultados encontrados" << endl;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);
			for (index i : found) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				f.print();
			}

			system("pause");
			system("cls");
		}
		else if (option == 7) {
			system("cls");

			string to_find;
			cout << "Procurar por: ";
			cin >> to_find;
			//pesquisar na árvore de ID, criar o feature a partir do arquivo
			vector<index> found = countryTree._find(to_find);

			cout << endl << found.size() << " resultados encontrados" << endl;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);
			for (index i : found) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				f.print();
			}

			system("pause");
			system("cls");

		}
		else if (option == 8) {
			system("cls");

			string to_find;
			cout << "Procurar por: ";
			cin >> to_find;
			//pesquisar na árvore de ID, criar o feature a partir do arquivo
			vector<index> found = yearTree._find(to_find);

			cout << endl << found.size() << " resultados encontrados" << endl;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);
			for (index i : found) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				f.print();
			}

			system("pause");
			system("cls");
		}
		else if (option == 9) {
			system("cls");

			string key, ind;
			cout << "Index to search: ";
			cin >> ind;
			cout << endl << "Key to remove: ";
			cin >> key;
			if (ind == "id") {
				vector<index> found = idTree._find(key);
				if (!found.empty()) {
					for (index i : found) {
						cout << i.key << endl;
						cout << "Remove this feature?" << endl;
						cin >> key;
						if (key == "y" or key == "yes") {

						}
					}
				}
			}
			//escolher a árvore, encontrar e remover de todas as árvores, adicionar à delID

			system("pause");
			system("cls");
		}
		else if (option == 0) {
			//exporting
			idTree._export("id_index.csv");
			typeTree._export("type_index.csv");
			titleTree._export("title_index.csv");
			directorTree._export("director_index.csv");
			castTree._export("cast_index.csv");
			countryTree._export("country_index.csv");
			yearTree._export("year_index.csv");
			return 0;
		}
		else
		{
			cout << "Esta opção não existe! Voltando ao menu..." << endl;
			system("pause");
			system("cls");
		}
	}
}
//cadastro(inserir e remover) e consulta do banco de dados por indexação em arvore B
	//sobrecarregar remoção para retornar o index marcado e jogar ele em outra árvore/arquivo
//inserção e remoção locais /não precise reorganizar
	//semelhante à passada mas
//cada página da árvore com 4KB ou menos
	//refazer os cálculos para o novo index com bytes
	//uma maneira automática seria coletar todos os indexes antes da remoção e usar o maior como referência para
	// o cálculo, 2t-1=4000/maxSize, mas isso ainda poderia dar errado ao inserir um maior
//minimizar o número se seeks
	//não sei como utilizar seeks no modelo atual, talvez use getline <-ler arquivo de index p/btree

//usar stringstream igual em index para importar index p/ arvore
//usar um find(_), todo index tem "_", se não achar não importar