#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <sstream>

Graph::Graph(const std::string& filename_nodes, const std::string& filename_edges) {
    std::cout << "nodes" << std::endl;
    //read nodes
    std::ifstream ifs_nodes{filename_nodes};
    if (!ifs_nodes.is_open()) {
        throw std::invalid_argument("File could not be opened.");
    }
    if (ifs_nodes.bad()) {
        throw std::invalid_argument("File could not be read"); //not sure about this one
    }

    std::string id;
    std::string latitude;
    std::string longitude;
    while (ifs_nodes.good()) {
        ifs_nodes >> id >> latitude >> longitude;
        std::cout << id << " " << latitude << " " << longitude << std::endl;
        Node node{std::stoi(id), std::stod(latitude), std::stod(longitude)};
        graph.insert(std::pair<Node, std::vector<Connection>>(node, {}));
    }



    std::cout << "edges" << std::endl;
    //read edges
    std::ifstream ifs_edges{filename_edges};
    if (!ifs_edges.is_open()) {
        throw std::invalid_argument("File could not be opened.");
    }
    if (ifs_edges.bad()) {
        throw std::invalid_argument("File could not be read"); //not sure about this one
    }

    std::string input2;
    while (std::getline(ifs_edges, input2)) {
    }

}
