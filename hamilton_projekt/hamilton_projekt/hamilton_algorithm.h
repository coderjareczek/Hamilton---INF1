#pragma once

#include "input_output.h"

/** Funkcja DFS przetwarza wszystkie dostêpne wierzcho³ki grafu.
 * Parametry s¹ przekazane przez wartoœæ lub referencjê.
 * @param v pocz¹tkowy wierzcho³ek
 * @param[in, out] current_weight waga obecnej œcie¿ki
 * @param[in, out] best_weight waga œcie¿ki o najmniejszej wadze
 * @param[in, out] visited wektor odwiedzonych wierzcho³ków
 * @param[in, out] current_path wektor zawieraj¹cy aktualni¹ œcie¿kê
 * @param best_path[in, out] wektor zawieraj¹cy najkrótsz¹ œcie¿ka Hamiltona
 * @param adjacenecy_list lista s¹siedztwa zawieraj¹ca graf
 */
void DFS(int v, int& current_weight, int& best_weight, std::vector<bool>& visited, std::vector<int>& current_path, std::vector<int>& best_path, const graph_struct adjacency_list);

/** Funkcja znajduje najkrótsz¹ œcie¿kê Hamiltona.
 * Parametry s¹ przekazane przez wartoœæ lub referencjê.
 * @param adjacenecy_list lista s¹siedztwa zawieraj¹ca graf
 * @param config konfiguracje, zawieraj¹ pocz¹tkowy wierzcho³ek œcie¿ki
 * @param best_path[in, out] wektor zawieraj¹cy najkrótsz¹ œcie¿ka Hamiltona
 * @return zwraca true kiedy uda³o siê znaleŸæ œcie¿kê
 */
bool find_the_path(const graph_struct adjacency_list, const config_struct config, std::vector<int>& best_path);