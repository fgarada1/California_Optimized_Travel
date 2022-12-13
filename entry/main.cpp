#include <iostream>
#include <fstream>
#include "Graph.h"

int main() {
    bool input = true;

    std::cout << "Use example graph? Type 1 -> Yes, Type 0 = No " << std::endl;

    std::cin >> input;

    std::string nodes_file;
    std::string edges_file;
    size_t num_nodes = 0;
    size_t num_edges = 0;

    if (input) {
        nodes_file = "../ol_nodes.txt";
        edges_file = "../ol_edges.txt";
        num_nodes = 6105;
        num_edges = 7035;
    } else {

        std::cout << "Enter file path for nodes: " << std::endl;

        std::cin >> nodes_file;

        std::cout << "Total number of nodes: " << std::endl;

        std::cin >> num_nodes;

        std::cout << "Enter file path for edges: " << edges_file << std::endl;

        std::cin >> edges_file;

        std::cout << "Total number of edges: " << std::endl;

        std::cin >> num_edges;
    }

    Graph graph(nodes_file, edges_file, num_nodes, num_edges);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Which algorithm would you like to use? Type 0 for BFS, 1 for Astar, or 2 for Floyd Warshall: " << std::endl;

    size_t input2 = 0;

    std::cin >> input2;

    if (input2 == 0) {
        //run bfs
    } else if (input2 == 1) {
        bool input3 = true;
        std::cout << "Default heuristic?: Type 1 -> Yes, Type 0 -> No " << std::endl;
        std::cin >> input3;
        if (input3) {
            graph.compute_heuristic_matrix_pythagorean_distance();
        } else {
            bool input4 = true;
            std::cout << "Which heuristic?: Type 1 -> Pythagorean, Type 0 -> Haversine " << std::endl;
            std::cin >> input4;
            if (input4) {
                graph.compute_heuristic_matrix_pythagorean_distance();
            } else {
                graph.compute_heuristic_matrix_haversine();
            }
        }

        size_t starting_node_id = 0;
        size_t ending_node_id = 0;

        std::cout << "Enter starting node id:  " << std::endl;

        std::cin >> starting_node_id;

        std::cout << "Enter ending node id:  " << std::endl;

        std::cin >> ending_node_id;

        std::cout << graph.print_nodes(graph.compute_astar_path(starting_node_id, ending_node_id)) << std::endl;

    } else if (input2 == 2) { 
        graph.compute_floyd_warshall();
        std::cout << graph.print_floyd_warshall() << std::endl;
    }
    
    bool input5 = false;

    std::cout << "Would you like to print all variables? Type 1 -> Yes, Type 0 = No " << std::endl;

    std::cin >> input5;

    if (input5) {
        graph.print_all_vars();
    }

}
