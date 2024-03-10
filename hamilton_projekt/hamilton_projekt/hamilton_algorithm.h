#pragma once

#include "input_output.h"

/** Funkcja DFS przetwarza wszystkie dost�pne wierzcho�ki grafu.
 * Parametry s� przekazane przez warto�� lub referencj�.
 * @param v pocz�tkowy wierzcho�ek
 * @param[in, out] current_weight waga obecnej �cie�ki
 * @param[in, out] best_weight waga �cie�ki o najmniejszej wadze
 * @param[in, out] visited wektor odwiedzonych wierzcho�k�w
 * @param[in, out] current_path wektor zawieraj�cy aktualni� �cie�k�
 * @param best_path[in, out] wektor zawieraj�cy najkr�tsz� �cie�ka Hamiltona
 * @param adjacenecy_list lista s�siedztwa zawieraj�ca graf
 */
void DFS(int v, int& current_weight, int& best_weight, std::vector<bool>& visited, std::vector<int>& current_path, std::vector<int>& best_path, const graph_struct adjacency_list);

/** Funkcja znajduje najkr�tsz� �cie�k� Hamiltona.
 * Parametry s� przekazane przez warto�� lub referencj�.
 * @param adjacenecy_list lista s�siedztwa zawieraj�ca graf
 * @param config konfiguracje, zawieraj� pocz�tkowy wierzcho�ek �cie�ki
 * @param best_path[in, out] wektor zawieraj�cy najkr�tsz� �cie�ka Hamiltona
 * @return zwraca true kiedy uda�o si� znale�� �cie�k�
 */
bool find_the_path(const graph_struct adjacency_list, const config_struct config, std::vector<int>& best_path);