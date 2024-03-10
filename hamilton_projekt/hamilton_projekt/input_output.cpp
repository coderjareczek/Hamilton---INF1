#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <limits>
#include "input_output.h"


bool read_command_line_arguments(cmd_args parameter, config_struct& config)
{
	if (parameter.argc == 1)
	{
		std::cout << "Oto program obliczajacy najkrotsza sciezke Hamiltona. Wprowadz nastepujace paratmetry:" << std::endl;
		std::cout << "-i <wejsciowy plik z grafem>" << std::endl;
		std::cout << "-o <wyjsciowy plik ze sciezka>" << std::endl;
		std::cout << "-s <numer poczatkowego wierzcholka sciezki>" << std::endl;
		return false;
	}

	if (parameter.argc < 7)
	{
		std::cout << "Zbyt mala liczba parametrow. Wymaganych parametrow 6." << std::endl;
		std::cout << "Uruchom program bez parametrow, aby zobczayc instrukcje." << std::endl;
		return false;
	}

	bool _i = 0, _o = 0, _s = 0;
	for (int i = 0; i < parameter.argc; i++)
	{
		if (parameter.argv[i] == std::string("-i"))
		{
			config.input = parameter.argv[i + 1];
			i++;
			_i = 1;
		}
		else if (parameter.argv[i] == std::string("-o"))
		{
			config.output = parameter.argv[i + 1];
			i++;
			_o = 1;
		}
		else if (parameter.argv[i] == std::string("-s"))
		{
			if (!is_number(std::string(parameter.argv[i + 1])))
			{
				std::cout << "-s musi byc liczba calkowita." << std::endl;
				std::cout << "Uruchom program bez parametrow, aby zobczayc instrukcje." << std::endl;
				return false;
			}
			config.vertex = stoi(std::string(parameter.argv[i + 1]));
			i++;
			_s = 1;
		}
	}
	if (!(_i and _o and _s))
	{
		std::cout << "Brak paratemtru" << std::endl;
		std::cout << "Uruchom program bez parametrow, aby zobczayc instrukcje." << std::endl;
		return false;
	}

	return true;
}

bool is_number(const std::string& s)
{
	for (char c : s)
	{
		if (!isdigit(c))
			return false;
	}
	return true;
}

bool read_graph(const config_struct config, graph_struct& adjacency_list)
{
	std::cout << "Plik wejscia: " << config.input<< std::endl;
	std::ifstream ifile(config.input);
	if (ifile)
	{
		int v1, v2, w;
		char trash, comma;

		while (ifile >> v1)
		{
			if (!(ifile >> trash >> trash >> v2 >> trash >> w >> trash))
			{
				std::cout << "Blad" << std::endl;
					return false;
			}
			ifile >> comma;
				 
			if (adjacency_list.graph.size() <= v1)
			{
				adjacency_list.graph.resize(v1 + 1);
			}
			edge edge_one;
			edge_one.vertex = v2;
			edge_one.weight = w;
			adjacency_list.graph[v1].push_back(edge_one);

		}
		
	}
	else
	{
		std::cout << "Nie mozna otworzyc pliku " << config.input << std::endl;
		return false;
	}
	std::cout << "Plik wyjscie: " << config.output << std::endl;
	std::cout << "Numer poczatkowego wierzcholka sciezki: " << config.vertex << std::endl;
	std::cout << "Zawartosc pliku wejscia: " << std::endl;
	for (auto const& some_list : adjacency_list.graph)
	{
		for (auto const& edge_element: some_list)
		{
			std::cout << edge_element.vertex << " " << edge_element.weight << "\t";
		}
		std::cout << std::endl;	}
	std::cout << std::endl;
	return true;
}

bool output_the_path(const config_struct config, std::vector<int> best_path)
{
	std::ofstream ofile(config.output);
	if (!ofile)
		return false;
	
	for (int vertex : best_path)
		ofile << vertex << " ";
}