#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <sstream>

Graph::Graph(const std::string& filename_nodes, const std::string& filename_edges, unsigned total_nodes, unsigned total_edges) 
: graph_(total_nodes, std::vector<double>(total_nodes, -1)), 
    predecessor_(total_nodes, std::vector<unsigned>(total_nodes, -1)), 
    nodes_(total_nodes, nullptr), 
    total_nodes_(total_nodes), total_edges_(total_edges) {

    //read nodes
    std::cout << "nodes" << std::endl;
    std::ifstream ifs_nodes{filename_nodes};
    if (!ifs_nodes.is_open()) {
        throw std::invalid_argument("File 1 could not be opened.");
    }
    if (ifs_nodes.bad()) {
        throw std::invalid_argument("File 1 could not be read"); //not sure about this one
    }

    //read through all of the lines in the nodes txt file
    unsigned count = 0;
    while (ifs_nodes.good() && count < total_nodes_) {
        unsigned id;
        std::string latitude;
        std::string longitude;

        ifs_nodes >> id;
        if (ifs_nodes.good()) {
            ifs_nodes >> latitude;
        } else {
            throw std::invalid_argument("Format 1 read error on line: " + std::to_string(count));
        }
        if (ifs_nodes.good()) {
            ifs_nodes >> longitude;
        } else {
            throw std::invalid_argument("Format 1 read error on line: " + std::to_string(count));
        }

        std::cout << id << " " << latitude << " " << longitude << std::endl;
        unsigned id2 = id; //used to convert from std::string to int previously
        Node* node = new Node{id2, std::stod(latitude), std::stod(longitude)}; //this guarantees higher precision for the doubles
            //also without new the first Node id wraps around to the max value, it goes wrong somehow, so this is the solution for now
        assert(nodes_.at(id2) == nullptr);
        nodes_.at(id2) = node;

        try {
            graph_.at(id2).at(id2) = 0;
            predecessor_.at(id2).at(id2) = id2;
        } catch (std::exception& e) {
            if (id2 >= total_nodes) {
                throw std::invalid_argument("given id: " + std::to_string(id2) + " on line: " + std::to_string(count) + " out of range of total_nodes_: " + std::to_string(total_nodes_));
            }
            throw std::invalid_argument("total_nodes_ is fewer than the number of nodes provided: "
                                                                    + std::to_string(total_nodes_));
        }
        count++;
    }
    //check if nodes txt file has extra lines
    std::string test;
    ifs_nodes >> test;
    ifs_nodes >> test;
    std::cout << test << std::endl;
    if (!ifs_nodes.eof()) {
        throw std::invalid_argument("total_nodes_ does not match the number of nodes provided: "
                                "document has extra entries on line: " + std::to_string(count));
    }
    if (count != total_nodes_) {
        throw std::invalid_argument("total_nodes_ does not match the number of nodes provided: count: " 
                             + std::to_string(count) + " total_nodes_: " + std::to_string(total_nodes_));
    }


    //read edges
    std::cout << "edges" << std::endl;
    std::ifstream ifs_edges{filename_edges};
    if (!ifs_edges.is_open()) {
        throw std::invalid_argument("File 2 could not be opened.");
    }
    if (ifs_edges.bad()) {
        throw std::invalid_argument("File 2 could not be read"); //not sure about this one
    }

    //read through all of the lines in the edgess txt file
    unsigned count2 = 0;
    while (ifs_edges.good() && count2 < total_edges_) {
        unsigned id_edge;
        unsigned id_to;
        unsigned id_from;
        std::string distance;

        ifs_edges >> id_edge;
        if (ifs_edges.good()) {
            ifs_edges >> id_to;
        } else {
            throw std::invalid_argument("Format 2 read error on line: " + std::to_string(count2));
        }
        if (ifs_edges.good()) {
            ifs_edges >> id_from;
        } else {
            throw std::invalid_argument("Format 2 read error on line: " + std::to_string(count2));
        }
        if (ifs_edges.good()) {
            ifs_edges >> distance;
        } else {
            throw std::invalid_argument("Format 2 read error on line: " + std::to_string(count2));
        }

        std::cout << id_edge << " " << id_to << " " << id_from << " " << distance << std::endl;
        try {
            graph_.at(id_from).at(id_to) = std::stod(distance);
            predecessor_.at(id_from).at(id_to) = id_from; //not sure if this is the correct thing to do here, based on ? floyd-warshall's algorithm
        } catch (std::exception& e) {
            //these should go before the try catch, but then the code does not work for some reason
            if (id_from >= total_nodes) {
                throw std::invalid_argument("id_from: " + std::to_string(id_from) + " on line: " + std::to_string(count2) + " out of range of total_nodes_: " + std::to_string(total_nodes_));
            }
            if (id_to >= total_nodes) {
                throw std::invalid_argument("id_to: " + std::to_string(id_to) + " out of range of total_nodes_: " + std::to_string(total_nodes_));
            }
            //
            throw std::invalid_argument("total_edges_ is fewer than the number of edges provided: "
                                                                    + std::to_string(total_edges_));
        }
        count2++;
    }
    //check if edges txt file has extra lines
    std::string test2;
    ifs_edges >> test2;
    ifs_edges >> test2;
    if (!ifs_edges.eof()) {
            throw std::invalid_argument("total_edges_ does not match the number of edges provided: "
                                    "document has extra entries on line: " + std::to_string(count2));
        }
    if (count2 != total_nodes_) {
        throw std::invalid_argument("total_edges_ does not match the number of edges provided: count: " 
                             + std::to_string(count2) + " total_edges_: " + std::to_string(total_edges_));
    }

}

Graph::~Graph() {
    // for (unsigned i = 0; i < total_nodes_; i++) {
    //     for (unsigned j = 0; j < total_nodes_; j++) {
    //         delete graph_.at(i).at(j);
    //         delete predecessor_.at(i).at(j);
    //     }
    // }
}

void Graph::print_graph() {
    std::cout << '\n' << std::endl;
    for (const std::vector<double>& vect : graph_) {
        for (double distance : vect) {
            // if (node_ptr != -1) {
                std::cout << distance << " ";
            // } else {
            //     std::cout << "null\t";
            // }
        }
        std::cout << '\n' << std::endl;
    }
    std::cout << std::endl;
}
void Graph::print_predecessors() {
    std::cout << '\n' << std::endl;
    for (const std::vector<unsigned>& vect : predecessor_) {
        for (unsigned predecessor : vect) {
            std::cout << predecessor << " ";
        }
        std::cout << '\n' << std::endl;
    }
    std::cout << std::endl;
}

void Graph::print_nodes() {
    std::cout << '\n' << std::endl;
    for (Node* node : nodes_) {
        if (node != nullptr) {
            std::cout << "[" << node->longitude << " " << node->longitude << "] ";
        } else {
            std::cout << "null ";
        }
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
