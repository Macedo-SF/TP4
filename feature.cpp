#include "feature.h"

/*
 * Construtor da classe Program. Ao ser convocado, faz a inserção
 * de cada parte da linha em sua respectiva variável.
 *
 * @param linha Linha lida do arquivo a ser inserida nas variáveis.
 */
feature::feature(char *linha)
{
    std::stringstream s(linha);
    std::string word;

    getline(s, word, ';');
    show_id = word;
    getline(s, word, ';');
    type = word;
    getline(s, word, ';');
    title = word;
    getline(s, word, ';');
    director = word;
    getline(s, word, ';');
    cast = word;
    getline(s, word, ';');
    country = word;
    getline(s, word, ';');
    date_added = word;
    getline(s, word, ';');
    release_year = stoi(word);
    getline(s, word, ';');
    rating = word;
    getline(s, word, ';');
    duration = word;
    getline(s, word, ';');
    listed_in = word;
    getline(s, word, ';');
    description = word;

}

/*
 * Construtor padrão da classe Program. Ao ser convocado, pede ao
 * usuário a inserção dos dados.
 */
feature::feature()
{
    std::cout << "Insert: " << std::endl << "Type: ";
    std::cin >> type;
    std::cout << std::endl << "Title: ";
    std::cin >> title;
    std::cout << std::endl << "Director: ";
    std::cin >> director;
    std::cout << std::endl << "Cast: ";
    std::cin >> cast;
    std::cout << std::endl << "Country: ";
    std::cin >> country;
    std::cout << std::endl << "Date added: ";
    std::cin >> date_added;
    std::cout << std::endl << "Release year: ";
    std::cin >> release_year;
    std::cout << std::endl << "Rating: ";
    std::cin >> rating;
    std::cout << std::endl << "Duration: ";
    std::cin >> duration;
    std::cout << std::endl << "Listed in: ";
    std::cin >> listed_in;
    std::cout << std::endl << "Description: ";
    std::cin >> description;
}

/*
 * Faz a impressão dos dados da classe na tela.
 */
void feature::print()
{
    std::cout << show_id << std::endl << type << std::endl << title << std::endl << director << std::endl << cast << std::endl << country << std::endl
         << date_added << std::endl << release_year << std::endl << rating << std::endl << duration << std::endl << listed_in << std::endl
         << description << std::endl << std::endl;
}

