#include <iostream>
#include <vector>
#include <list>
#include "input_output.h"

void DFS(int v, int& current_weight, int& best_weight, std::vector<bool>& visited, std::vector<int>& current_path, std::vector<int>& best_path, const graph_struct adjacency_list)

{
	visited[v] = true;
	current_path.push_back(v);

	std::cout << v << " przetworzony" << std::endl; // docelowo usun¹æ

	for (auto const& edge_element : adjacency_list.graph[v])
		if (!visited[edge_element.vertex])
		{
			current_weight += edge_element.weight;
			DFS(edge_element.vertex, current_weight, best_weight, visited, current_path, best_path, adjacency_list);
			current_weight -= edge_element.weight;
		}

	if (current_path.size() == adjacency_list.graph.size() && current_weight <= best_weight)
	{
		best_path = current_path;
		best_weight = current_weight;
	}

	visited[v] = false;
	current_path.pop_back();

}

bool find_the_path(const graph_struct adjacency_list, const config_struct config, std::vector<int>& best_path)
{
	const int n = adjacency_list.graph.size();
	std::vector<bool> visited(n, false);
	std::vector<int> current_path;
	int current_weight = 0;
	int best_weight = std::numeric_limits<int>::max();

	DFS(config.vertex, current_weight, best_weight, visited, current_path, best_path, adjacency_list);

	// Wyœwietlenie najlepszej znalezionej œcie¿ki - docelowo usun¹æ wypisywanie
	if (best_path.size() == n) {
		std::cout << "Znaleziona sciezka Hamiltona: ";
		for (int vertex : best_path) {
			std::cout << vertex << " ";
		}
		std::cout << std::endl;
		std::cout << "Waga minimalnej sciezki Hamiltona: " << best_weight << std::endl;
		return true;
	}
	else {
		std::cout << "Brak sciezki Hamiltona" << std::endl;
		return false;
	}
}