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

/** Funkcja wczytuje parametry z wiersza poleceñ.
 * Parametry s¹ przekazane przez wartoœæ lub referencjê.
 * @param parameter parametry wprowadzone przez u¿ytkownika
 * @param config[in, out] konfiguracje odczytane z parametrów
 * @return zwraca true kiedy uda³o siê odczytaæ parametry
 */
bool read_command_line_arguments(cmd_args parameter, config_struct& config);

/** Funkcja sprawdza czy dany string jest liczb¹.
 * Parametr jest przekazany przez wartoœæ.
 * @param s string do zbadanie
 * @return zwraca true kiedy string jest liczb¹
 */
bool is_number(const std::string& s);

/** Funkcja wczytujê graf z pliku do struktury danych.
 * Parametry s¹ przekazane przez wartoœæ lub referencjê.
 * @param config konfiguracje, zawieraj¹ nazwê pliku, z którego odczytujemy graf
 * @param[in, out] adjacenecy_list lista s¹siedztwa, do której wczytujemy graf
 * @return zwraca true kiedy uda³o siê wczytaæ graf
 */
bool read_graph(const config_struct config, graph_struct& adjacency_list);

/** Funkcja generuje plik ze znalezion¹ najkrótsz¹ œcie¿k¹.
 * Parametry s¹ przekazane przez wartoœæ.
 * @param config konfiguracje, zawieraj¹ nazwê pliku, do którego zapisujemy œcie¿kê
 * @param best_path najkrótsza œcie¿ka Hamiltona
 * @return zwraca true kiedy uda³o siê wygenerowaæ plik
 */
bool output_the_path(const config_struct config, std::vector<int> best_path);