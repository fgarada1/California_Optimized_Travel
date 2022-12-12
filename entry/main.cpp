#include <iostream>
#include "Graph.h"


using namespace std;
int main() {
    std::cout << "Hello, world!" << std::endl;
    // Graph graph("../more_test/example_nodes.txt", "../more_test/example_edges.txt", 41);
    // Graph graph("../more_test/example_nodes2.txt", "../more_test/example_edges2.txt", 11, 11); //supposed to cause an error on line 8 of "../example_edges2.txt"
    Graph graph("../test_nodes.txt", "../test_edges.txt", 11, 11);
    graph.print_graph();
    graph.print_all_vars();
    //graph.print_graph();
   // cout << "now printing predecessors" << endl;
   // graph.print_predecessors();
   map<std::pair<int, int>, int> a_;
   a_[make_pair(0,1)] = 10;
   cout << "map: " << a_.at(make_pair(0,1)) << endl;
}
