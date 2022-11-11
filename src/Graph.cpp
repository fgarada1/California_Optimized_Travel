#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <sstream>

Graph::Graph(const std::string& filename_nodes, const std::string& filename_edges, int total_nodes) : graph_(total_nodes, std::vector<Node*>(total_nodes, nullptr)), predecessor_(total_nodes, std::vector<int>(total_nodes, -1)){
    std::cout << "nodes" << std::endl;
    //read nodes
    std::ifstream ifs_nodes{filename_nodes};
    if (!ifs_nodes.is_open()) {
        throw std::invalid_argument("File could not be opened.");
    }
    if (ifs_nodes.bad()) {
        throw std::invalid_argument("File could not be read"); //not sure about this one
    }

    int id;
    std::string latitude;
    std::string longitude;
    int count = 0;
    while (ifs_nodes.good() && count < total_nodes) {
        ifs_nodes >> id;
        if (ifs_nodes.good()) {
            ifs_nodes >> latitude;
        } else {
            throw std::invalid_argument("Format read error on line: " + std::to_string(count));
        }
        if (ifs_nodes.good()) {
            ifs_nodes >> longitude;
        } else {
            throw std::invalid_argument("Format read error on line: " + std::to_string(count));
        }

        std::cout << id << " " << latitude << " " << longitude << std::endl;
        int id2 = id; //used to convert from std::string to int previously
        Node node{id2, std::stod(latitude), std::stod(longitude)}; //this guarantees higher precision for the doubles
        try {
            graph_.at(id2).at(id2) = &node;
            predecessor_.at(id2).at(id2) = id2;
        } catch (std::exception& e) {
            throw std::invalid_argument("total_nodes is fewer than the number of nodes provided: "
                                                                    + std::to_string(total_nodes));
        }
        count++;
    }
    try {
        ifs_nodes >> id;
        if (!ifs_nodes.bad()) {
            throw std::invalid_argument("total_nodes does not match the number of nodes provided: "
                                    "document has extra entries on line: " + std::to_string(count));
        }
    } catch (std::exception& e) {
    }
    if (count != total_nodes) {
        throw std::invalid_argument("total_nodes does not match the number of nodes provided: count: " 
                             + std::to_string(count) + " total_nodes: " + std::to_string(total_nodes));
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

void Graph::print_graph() {
    std::cout << '\n' << std::endl;
    for (std::vector<Node*> vect : graph_) {
        for (Node* node_ptr : vect) {
            if (node_ptr != nullptr) {
                std::cout << node_ptr->id << "\t";
            } else {
                std::cout << "null\t";
            }
        }
        std::cout << '\n' << std::endl;
    }
    std::cout << std::endl;
}
void Graph::print_predecessors() {
    std::cout << '\n' << std::endl;
    for (std::vector<int> vect : predecessor_) {
        for (int num : vect) {
            std::cout << num << "\t";
        }
        std::cout << '\n' << std::endl;
    }
    std::cout << std::endl;
}

void Graph::print(const std::vector<std::vector<Node*>>& graph) {
    std::cout << '\n' << std::endl;
    for (std::vector<Node*> vect : graph) {
        for (Node* node_ptr : vect) {
    //         std::cout << node_ptr->id << " ";
        }
    }
    std::cout << std::endl;
}
