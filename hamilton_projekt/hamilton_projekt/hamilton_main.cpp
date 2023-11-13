#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	std::string input_file_name, output_file_name;
	int starting_vertex;

	if (argc == 1)
	{
		std::cout << "Oto program obliczajacy najkrotsza sciezke Hamiltona. Wprowadz nastepujace paratmetry:" << std::endl;
		std::cout << "-i <wejsciowy plik z grafem>" << std::endl;
		std::cout << "-o <wyjsciowy plik ze sciezka>" << std::endl;
		std::cout << "-s <numer poczatkowego wierzcholka sciezki>" << std::endl;
		return 1;
	}
	
	if (argc < 7)
	{
		std::cout << "Zbyt mala liczba parametrow. Wymaganych parametrow 6." << std::endl;
		std::cout << "Uruchom program bez parametrow aby zobczayc instrukcje." << std::endl;
		return 1;
	}

	for (int i = 0; i < argc; i++)
	{
		bool _i = 0, _o = 0, _s = 0;
		if (argv[i] == std::string("-i"))
		{
			input_file_name = argv[i + 1];
			i++;
			_i = 1;
		}
		else if (argv[i] == std::string("-o"))
		{
			output_file_name = argv[i + 1];
			i++;
			_o = 1;
		}
		else if (argv[i] == std::string("-s"))
		{
			starting_vertex = stoi(std::string(argv[i + 1]));
			i++;
			_s = 1;
		}
		//if (!(_i and _o and _s))
		//{
		//	std::cout << "Brak paratemtru" << std::endl;
		//	std::cout << "Uruchom program bez parametrow aby zobczayc instrukcje." << std::endl;
		//	return 1;
		//}
	}
	
	//todo check if starting point is a number



	//check values  
	std::cout << input_file_name << std::endl;
	std::cout << output_file_name << std::endl;
	std::cout << starting_vertex << std::endl;
	return 0;
}