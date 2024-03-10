#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "input_output.h"
#include "hamilton_algorithm.h"

int main(int argc, char** argv)
{
	cmd_args parameter;
	parameter.argc = argc;
	parameter.argv = argv;
	
	config_struct config;
	
	if (!read_command_line_arguments(parameter, config))
		return 1;
	
	graph_struct adjacency_list;
	
	if (!read_graph(config, adjacency_list))
		return 1;
	
	std::vector<int> best_path;
	
	if (!find_the_path(adjacency_list, config, best_path))
		return 1;
	if (!output_the_path(config, best_path))
		return 1;
	


	return 0;
}