#include "BTree.h"
#include "feature.h"

using namespace std;

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

			//pesquisar na árvore de type, criar o feature a partir do arquivo

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

			//pesquisar na árvore de title, criar o feature a partir do arquivo

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
			//pesquisar na árvore de director, criar o feature a partir do arquivo

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

			//pesquisar na árvore de cast, criar o feature a partir do arquivo

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

			//pesquisar na árvore de country, criar o feature a partir do arquivo

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

			//pesquisar na árvore de year, criar o feature a partir do arquivo

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
			vector<index> to_remove;
			fstream file(filename, ios::in);
			char buffer[tam + 1];
			file.getline(buffer, tam);

			cout << "Index a procurar: ";
			cin >> ind;
			cout << endl << "Chave a remover: ";
			cin >> key;
			if (ind == "id") {
				vector<index> found = idTree._find(key);
				if (!found.empty()) {
					cout << endl << found.size() << " resultados encontrados" << endl;
					for (index i : found) {
						file.seekg(i.pos);
						file.getline(buffer, tam);
						feature f(buffer);
						f.print();
						cout << "Remover esse feature?" << endl;
						cin >> key;
						if (key == "s" or key == "sim") {
							to_remove.push_back(i);
						}
					}
				}
			}
			if (ind == "type") {
				vector<index> found = typeTree._find(key);
				if (!found.empty()) {
					cout << endl << found.size() << " resultados encontrados" << endl;
					for (index i : found) {
						file.seekg(i.pos);
						file.getline(buffer, tam);
						feature f(buffer);
						f.print();
						cout << "Remover esse feature?" << endl;
						cin >> key;
						if (key == "s" or key == "sim") {
							to_remove.push_back(i);
						}
					}
				}
			}
			if (ind == "title") {
				vector<index> found = titleTree._find(key);
				if (!found.empty()) {
					cout << endl << found.size() << " resultados encontrados" << endl;
					for (index i : found) {
						file.seekg(i.pos);
						file.getline(buffer, tam);
						feature f(buffer);
						f.print();
						cout << "Remover esse feature?" << endl;
						cin >> key;
						if (key == "s" or key == "sim") {
							to_remove.push_back(i);
						}
					}
				}
			}
			if (ind == "director") {
				vector<index> found = directorTree._find(key);
				if (!found.empty()) {
					cout << endl << found.size() << " resultados encontrados" << endl;
					for (index i : found) {
						file.seekg(i.pos);
						file.getline(buffer, tam);
						feature f(buffer);
						f.print();
						cout << "Remover esse feature?" << endl;
						cin >> key;
						if (key == "s" or key == "sim") {
							to_remove.push_back(i);
						}
					}
				}
			}
			if (ind == "cast") {
				vector<index> found = castTree._find(key);
				if (!found.empty()) {
					cout << endl << found.size() << " resultados encontrados" << endl;
					for (index i : found) {
						file.seekg(i.pos);
						file.getline(buffer, tam);
						feature f(buffer);
						f.print();
						cout << "Remover esse feature?" << endl;
						cin >> key;
						if (key == "s" or key == "sim") {
							to_remove.push_back(i);
						}
					}
				}
			}
			if (ind == "country") {
				vector<index> found = countryTree._find(key);
				if (!found.empty()) {
					cout << endl << found.size() << " resultados encontrados" << endl;
					for (index i : found) {
						file.seekg(i.pos);
						file.getline(buffer, tam);
						feature f(buffer);
						f.print();
						cout << "Remover esse feature?" << endl;
						cin >> key;
						if (key == "s" or key == "sim") {
							to_remove.push_back(i);
						}
					}
				}
			}
			if (ind == "year") {
				vector<index> found = yearTree._find(key);
				if (!found.empty()) {
					cout << endl << found.size() << " resultados encontrados" << endl;
					for (index i : found) {
						file.seekg(i.pos);
						file.getline(buffer, tam);
						feature f(buffer);
						f.print();
						cout << "Remover esse feature?" << endl;
						cin >> key;
						if (key == "s" or key == "sim") {
							to_remove.push_back(i);
						}
					}
				}
			}
			//escolher a árvore, encontrar e remover de todas as árvores, adicionar à delID
			
			for (index i : to_remove) {
				file.seekg(i.pos);
				file.getline(buffer, tam);
				feature f(buffer);
				idTree.remove(index(f.show_id, i.pos));
				typeTree.remove(index(f.type, i.pos));
				titleTree.remove(index(f.title, i.pos));
				directorTree.remove(index(f.director, i.pos));
				castTree.remove(index(f.cast, i.pos));
				countryTree.remove(index(f.country, i.pos));
				yearTree.remove(index(f.release_year, i.pos));
			}
			//^esse metodo funciona apenas para valores únicos, por falta de tempo, terei de improvisar
			file.close();
			file.open(filename, ios::in | ios::out);
			file.getline(buffer, tam);
			for (index i : to_remove) {
				file.seekp(i.pos);
				file << "-";
			}

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