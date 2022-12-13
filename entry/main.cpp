#include <iostream>
#include "Graph.h"


using namespace std;
int main() {
    std::cout << "Hello, world!" << std::endl;
    Graph graph("../test_nodes.txt", "../test_edges.txt", 11, 11);
    // Graph graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8);
    // Graph graph("../more_test/example_nodes.txt", "../more_test/example_edges.txt", 41);
    // Graph graph("../more_test/example_nodes2.txt", "../more_test/example_edges2.txt", 11, 11); //supposed to cause an error on line 8 of "../example_edges2.txt"

    // Graph graph("../more_test/example_nodes3.txt", "../more_test/example_edges3.txt", 11, 11); //not supposed to cause an error
    // Graph graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
    // Graph graph("../sf_nodes.txt", "../sf_edges.txt", 174956, 223001); //not supposed to cause an error
    // Graph graph("../cal_road_nodes.txt", "../cal_road_edges.txt", 17000, 16000); //not supposed to cause an error
    // Graph graph("../cal_road_nodes.txt", "../cal_road_edges.txt", 21047, 21692); //not supposed to cause an error
    // Graph graph("../ol_nodes.txt", "../ol_edges.txt", 6105, 7035); //not supposed to cause an error
    // Graph graph("../ol_nodes.txt", "../ol_edges.txt", 6105, 35); //not supposed to cause an error

    graph.print_all_vars();
    // std::cout << graph.print_floyd_warshall() << std::endl;
    // std::cout << graph.print_predecessors() << std::endl;

    // graph.compute_floyd_warshall();
    // graph.print_graph();
    // graph.print_predecessors();
    // std::cout << graph.print_floyd_warshall() << std::endl;
    // std::cout << graph.print_predecessors() << std::endl;

    // graph.compute_dijkstra_path(0, 1);
    // for (Node* node : graph.shortest_path_floyd_warshall(0, 1)) {
    //     std::cout << node->print() << std::endl;
    // }
    // std::cout << "All Nodes in the end: " << std::endl;
    // for (Node* node : graph.compute_dijkstra_path(0, 1)) {
    //     if (node != nullptr) {
    //         std::cout << node->print() << std::endl;
    //     } else {
    //         std::cout << "null" << std::endl;
    //     }
    // }
    // std::cout << "All Nodes in the end: " << std::endl;
    // for (Node* node : graph.compute_astar_path(0, 1)) {
    //     if (node != nullptr) {
    //         std::cout << node->print() << std::endl;
    //     } else {
    //         std::cout << "null" << std::endl;
    //     }
    // }
    // std::cout << graph.print_nodes(graph.compute_dijkstra_path(1, 6)) << std::endl;
    // graph.compute_heuristic_matrix_pythagorean_distance();
    // std::cout << graph.print_nodes(graph.compute_dijkstra_path(1, 6)) << std::endl;

    // std::cout << "shortest_path_floyd_warshall" << std::endl;
    // for (Node* node : graph.shortest_path_floyd_warshall(0, 1)) {
    //     if (node != nullptr) {
    //         std::cout << node->print() << std::endl;
    //     } else {
    //         std::cout << "null" << std::endl;
    //     }
    // }
    // std::cout << graph.print_nodes(graph.shortest_path_floyd_warshall(0, 1)) << std::endl;


}
