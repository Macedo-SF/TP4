#pragma once

#include <iostream>
#include <sstream>


/*
 * Essa classe contém os atributos de um programa disponível
 * no catálogo.
 */
class feature {
public:
    std::string show_id = "NULL"; //Unique ID for every Movie / Tv Show
    std::string type = "NULL"; //Identifier - A Movie or TV Show
    std::string title = "NULL"; //Title of the Movie / Tv Show
    std::string director = "NULL"; // Director of the Movie
    std::string cast = "NULL"; // Actors involved in the movie / show
    std::string country = "NULL"; // Country where the movie / show was produced
    std::string date_added = "NULL"; // Date it was added on Netflix
    std::string release_year = 0; // Actual Release year of the move / show
    std::string rating = "NULL"; //TV Rating of the movie / show
    std::string duration = "NULL"; //Total Duration - in minutes or number of seasons
    std::string listed_in = "NULL"; //Genere
    std::string description = "NULL"; //The summary description

    /*
     * Construtor da classe Program. Ao ser convocado, faz a inserção
     * de cada parte da linha em sua respectiva variável.
     *
     * @param linha Linha lida do arquivo a ser inserida nas variáveis.
     */
    feature(char* linha);

    /*
     * Construtor padrão da classe Program. Ao ser convocado, pede ao
     * usuário a inserção dos dados.
     */
    feature();

    /*
     * Faz a impressão dos dados da classe na tela.
     */
    void print();

};
