#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    // Graph graph("../example_nodes.txt", "../example_edges.txt", 41);
    // Graph graph("../example_nodes2.txt", "../example_edges2.txt", 11, 11); //supposed to cause an error on line 8 of "../example_edges2.txt"
    Graph graph("../example_nodes3.txt", "../example_edges3.txt", 11, 11); //not supposed to cause an error
    graph.print_graph();
    graph.print_predecessors();
}
