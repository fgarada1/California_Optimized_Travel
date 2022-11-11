#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    // Graph graph("../example_nodes.txt", "../example_edges.txt", 41);
    Graph graph("../example_nodes2.txt", "../example_edges2.txt", 11);
    // graph.print_graph();
    graph.print_predecessors();
}
