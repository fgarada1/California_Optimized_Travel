#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    // Graph graph("../more_test/example_nodes.txt", "../more_test/example_edges.txt", 41);
    // Graph graph("../more_test/example_nodes2.txt", "../more_test/example_edges2.txt", 11, 11); //supposed to cause an error on line 8 of "../example_edges2.txt"
    Graph graph("../more_test/example_nodes3.txt", "../more_test/example_edges3.txt", 11, 11); //not supposed to cause an error
    graph.print_graph();
    graph.print_predecessors();
}
