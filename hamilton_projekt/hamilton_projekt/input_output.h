#pragma once

struct cmd_args
{
	int argc;
	char** argv;
};

struct config_struct
{
	int vertex;
	std::string input;
	std::string output;
};

struct edge
{
	int vertex; //vertex to which the edge points to
	int weight; //weight of the edge
};

struct graph_struct
{
	std::vector<std::list<edge>> graph;
};

/** Funkcja wczytuje parametry z wiersza polece�.
 * Parametry s� przekazane przez warto�� lub referencj�.
 * @param parameter parametry wprowadzone przez u�ytkownika
 * @param config[in, out] konfiguracje odczytane z parametr�w
 * @return zwraca true kiedy uda�o si� odczyta� parametry
 */
bool read_command_line_arguments(cmd_args parameter, config_struct& config);

/** Funkcja sprawdza czy dany string jest liczb�.
 * Parametr jest przekazany przez warto��.
 * @param s string do zbadanie
 * @return zwraca true kiedy string jest liczb�
 */
bool is_number(const std::string& s);

/** Funkcja wczytuj� graf z pliku do struktury danych.
 * Parametry s� przekazane przez warto�� lub referencj�.
 * @param config konfiguracje, zawieraj� nazw� pliku, z kt�rego odczytujemy graf
 * @param[in, out] adjacenecy_list lista s�siedztwa, do kt�rej wczytujemy graf
 * @return zwraca true kiedy uda�o si� wczyta� graf
 */
bool read_graph(const config_struct config, graph_struct& adjacency_list);

/** Funkcja generuje plik ze znalezion� najkr�tsz� �cie�k�.
 * Parametry s� przekazane przez warto��.
 * @param config konfiguracje, zawieraj� nazw� pliku, do kt�rego zapisujemy �cie�k�
 * @param best_path najkr�tsza �cie�ka Hamiltona
 * @return zwraca true kiedy uda�o si� wygenerowa� plik
 */
bool output_the_path(const config_struct config, std::vector<int> best_path);