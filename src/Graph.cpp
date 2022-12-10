#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <queue>
#include <set>
#include <limits>
#include <algorithm>
#include <numbers>
#include <math.h>

Graph::Graph(const std::string& filename_nodes, const std::string& filename_edges, unsigned total_nodes, unsigned total_edges) 
: graph_(total_nodes, std::vector<double>(total_nodes, std::numeric_limits<double>::max())), 
    predecessor_(total_nodes, std::vector<unsigned>(total_nodes, std::numeric_limits<unsigned>::max())), //change to int if it makes sense to do so
    floyd_warshall_(total_nodes, std::vector<double>(total_nodes, std::numeric_limits<double>::max())), 
    heuristic_(total_nodes, std::vector<double>(total_nodes, std::numeric_limits<double>::max())), 
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
        double latitude_double;
        double longitude_double;

        ifs_nodes >> id;
        if (ifs_nodes.good()) {
            ifs_nodes >> latitude;
            try {
                latitude_double = std::stod(latitude);
            } catch (std::exception& e) {
                throw std::invalid_argument("Format 1 read error on line: " + std::to_string(count));
            }
        } else {
            throw std::invalid_argument("Format 1 read error on line: " + std::to_string(count));
        }
        if (ifs_nodes.good()) {
            ifs_nodes >> longitude;
            try {
                longitude_double = std::stod(longitude);
            } catch (std::exception& e) {
                throw std::invalid_argument("Format 1 read error on line: " + std::to_string(count));
            }
        } else {
            throw std::invalid_argument("Format 1 read error on line: " + std::to_string(count));
        }

        std::cout << id << " " << latitude << " " << longitude << std::endl;
        unsigned id2 = id; //used to convert from std::string to int previously
        if (count != id2) {
            throw std::invalid_argument("given id: " + std::to_string(id2) + " does not match count: " + std::to_string(count));
        }
        if (id2 >= total_nodes) {
                throw std::invalid_argument("given id: " + std::to_string(id2) + " on line: " + std::to_string(count) + " out of range of total_nodes_: " + std::to_string(total_nodes_));
        }
        try {
            graph_.at(id2).at(id2) = 0;
            floyd_warshall_.at(id2).at(id2) = 0;
            predecessor_.at(id2).at(id2) = id2;
        } catch (std::exception& e) {
            throw std::invalid_argument("total_nodes_ is fewer than the number of nodes provided: "
                                                                    + std::to_string(total_nodes_));
        }

        Node* node = new Node{id2, latitude_double, longitude_double}; //this guarantees higher precision for the doubles
            //also without new the first Node id wraps around to the max value, it goes wrong somehow, so this is the solution for now
        assert(nodes_.at(id2) == nullptr);
        // try {
        //     if (nodes_.at(id2) == nullptr) {
        //     }
        // } catch (std::exception& e) {
        //     throw std::invalid_argument("given id: " + std::to_string(id2) + " does not match count: " + std::to_string(count));
        // }
        nodes_.at(id2) = node;
        
        count++;
    }
    //check if nodes txt file has extra lines
    std::string test;
    ifs_nodes >> test;
    ifs_nodes >> test;
    std::cout << test << std::endl;
    if (!ifs_nodes.eof()) {
        throw std::invalid_argument("total_nodes_ in document 1 does not match the number of nodes provided: "
                                "document 1 has extra entries on line: " + std::to_string(count));
    }
    if (count != total_nodes_) {
        throw std::invalid_argument("total_nodes_ in document 1 does not match the number of nodes provided: count: " 
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

    //read through all of the lines in the edges txt file
    unsigned count2 = 0;
    while (ifs_edges.good() && count2 < total_edges_) {
        unsigned id_edge;
        unsigned id_from;
        unsigned id_to;
        std::string distance;
        double distance_double;


        ifs_edges >> id_edge;
        if (ifs_edges.good()) {
            ifs_edges >> id_from;
        } else {
            throw std::invalid_argument("Format 2 read error on line: " + std::to_string(count2));
        }
        if (ifs_edges.good()) {
            ifs_edges >> id_to;
        } else {
            throw std::invalid_argument("Format 2 read error on line: " + std::to_string(count2));
        }
        if (ifs_edges.good()) {
            ifs_edges >> distance;
            try {
                distance_double = std::stod(distance);
            } catch (std::exception& e) {
                throw std::invalid_argument("Format 2 read error on line: " + std::to_string(count2));
            }
        } else {
            throw std::invalid_argument("Format 2 read error on line: " + std::to_string(count2));
        }

        std::cout << id_edge << " " << id_from << " " << id_to << " " << distance_double << std::endl;
        if (id_from >= total_nodes) {
            throw std::invalid_argument("id_from: " + std::to_string(id_from) + " on line: " + std::to_string(count2) + " out of range of total_nodes_: " + std::to_string(total_nodes_));
        }
        if (id_to >= total_nodes) {
            throw std::invalid_argument("id_to: " + std::to_string(id_to) + " out of range of total_nodes_: " + std::to_string(total_nodes_));
        }
        if (count2 != id_edge) {
            throw std::invalid_argument("given edge_id: " + std::to_string(id_edge) + " does not match count2: " + std::to_string(count2) );
        }
        if (id_from == id_to) {
            throw std::invalid_argument("Self loops are not allowed: id_from: " + std::to_string(id_from) + " and id_to: " + std::to_string(id_from) + " on line: " + std::to_string(count2) + " total_nodes:  " + std::to_string(total_nodes_));
            }
        try {
            graph_.at(id_from).at(id_to) = distance_double;
            floyd_warshall_.at(id_from).at(id_to) = distance_double;
            predecessor_.at(id_from).at(id_to) = id_from; //not sure if this is the correct thing to do here, based on ? floyd-warshall's algorithm
        } catch (std::exception& e) {
            //
            throw std::invalid_argument("total_edges_ in document 2 is fewer than the number of edges provided: "
                                                                    + std::to_string(total_edges_));
        }
        count2++;
    }
    //check if edges txt file has extra lines
    std::string test2;
    ifs_edges >> test2;
    ifs_edges >> test2;
    if (!ifs_edges.eof()) {
            throw std::invalid_argument("total_edges_ in document 2 does not match the number of edges provided: "
                                    "document 2 has extra entries on line: " + std::to_string(count2));
        }
    if (count2 != total_edges_) {
        throw std::invalid_argument("total_edges_ in document 2 does not match the number of edges provided: count2: " 
                             + std::to_string(count2) + " total_edges_: " + std::to_string(total_edges_));
    }

    compute_heuristic_adjacency_matrix();
    // floyd_warshall_ = graph_; //this is a copy, not a reference to graph_
}

Graph::~Graph() {
    // for (unsigned i = 0; i < total_nodes_; i++) {
    //     for (unsigned j = 0; j < total_nodes_; j++) {
    //         delete graph_.at(i).at(j);
    //         delete predecessor_.at(i).at(j);
    //     }
    // }
    for (Node* node : nodes_) {
       delete node;
    }
}

void Graph::compute_heuristic_adjacency_matrix() {
    assert(nodes_.size() == total_nodes_);
    assert(heuristic_.size() == total_nodes_);
    assert(graph_.size() == total_nodes_);
    //could assert that each row exists and has size == total_nodes, but this could be unneccessary and make compile time longer
    for (size_t i = 0; i < total_nodes_; i++) {
        for (size_t j = i; j < total_nodes_; j++) {
            // if (graph_.at(i).at(j) != std::numeric_limits<double>::max()) {
                // double distance = haversine(nodes_.at(i), nodes_.at(j));
                double distance = pythagorean_distance(nodes_.at(i), nodes_.at(j)); //because the data is given in normalized coordinates
                heuristic_.at(i).at(j) = distance;
                heuristic_.at(j).at(i) = distance;
            // }
        }
    }
}


double Graph::haversine(Node* node_from, Node* node_to) {
    // double delta_longitude = std::abs(node_from->longitude - node_to->longitude);
    // double delta_latitude = std::abs(node_from->latitude - node_to->latitude);

    double longitude2 = node_to->longitude;
    double longitude1 = node_from->longitude;
    double latitude2 = node_to->latitude;
    double latitude1 = node_from->latitude;

    // double scaled_distance = (sin(longitude2 - longitude1))*(sin(longitude2 - longitude1)) + cos(longitude1) * cos(longitude2)* (sin(latitude2 - latitude1))*(sin(latitude2 - latitude1));

    // const double kradius_earth = 6378100; //don't need this part, if they are all scaled by the same amount

    // double distance = scaled_distance*kradius_earth;

    //code copied from https://www.movable-type.co.uk/scripts/latlong.html
    // JavaScript:	
    // const R = 6371e3; // metres
    // const φ1 = lat1 * Math.PI/180; // φ, λ in radians
    // const φ2 = lat2 * Math.PI/180;
    // const Δφ = (lat2-lat1) * Math.PI/180;
    // const Δλ = (lon2-lon1) * Math.PI/180;

    // const a = Math.sin(Δφ/2) * Math.sin(Δφ/2) +
    //         Math.cos(φ1) * Math.cos(φ2) *
    //         Math.sin(Δλ/2) * Math.sin(Δλ/2);
    // const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));

    // const d = R * c; // in metres
    
    const double PI = 3.14159265359;

    const double R = 63.71; //in kilometers*100 as to not exceed the distance heuristic
    double lat1 = latitude1 * PI/180;
    double lat2 = latitude2 * PI/180;
    double lon1 = longitude1 * PI/180;
    double lon2 = longitude2 * PI/180;
    double delta_lat = (lat2 - lat1);
    double delta_lon = (lon2 - lon1);

    double a = sin(delta_lat/2) * sin(delta_lat/2) + cos(lat1) * cos(lat2) * sin(delta_lon/2) * sin(delta_lon/2);
    double c = 2 * atan2(std::sqrt(a), std::sqrt(1-a));

    double distance = R * c;

    return distance;
}

double Graph::pythagorean_distance(Node* node_from, Node* node_to) {
    double delta_longitude = std::abs(node_from->longitude - node_to->longitude);
    double delta_latitude = std::abs(node_from->latitude - node_to->latitude);

    // double longitude2 = node_to->longitude;
    // double longitude1 = node_from->longitude;
    // double latitude2 = node_to->latitude;
    // double latitude1 = node_from->latitude;

    double inside = delta_longitude*delta_longitude + delta_latitude*delta_latitude;

    double distance = std::sqrt(inside);

    return distance;
}


void Graph::compute_floyd_warshall() {
    //  print_floyd_warshall();
     int n = floyd_warshall_.size();
     for (int k = 0; k < n; k++) {
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) {
                 if (floyd_warshall_[i][k] + floyd_warshall_[k][j] < floyd_warshall_[i][j]) {
                     floyd_warshall_[i][j] = floyd_warshall_[i][k] + floyd_warshall_[k][j];
                     predecessor_[i][j] = predecessor_[k][j];
                 }
             }
         }
     }
    //  print_floyd_warshall();
}

std::vector<Node*> Graph::shortest_path_floyd_warshall(unsigned id_from, unsigned id_to) {
    //could combine both of these error messages into one
    if (id_from >= total_nodes_) {
        throw std::invalid_argument("id_from:  " + std::to_string(id_from) + " is out of range of total_nodes_: " + std::to_string(total_nodes_));
    }
    if (id_to >= total_nodes_) {
        throw std::invalid_argument("id_to:  " + std::to_string(id_to) + " is out of range of total_nodes_: " + std::to_string(total_nodes_));
    }
    std::vector<Node*> output; //not sure if returning an empty vector here is the best option that is available at the moment
    if (predecessor_.at(id_from).at(id_to) == std::numeric_limits<unsigned>::max()) { //0
        return output;
    }

    output.push_back(nodes_.at(id_from));

    unsigned current_input = id_from;
    unsigned current_output = predecessor_.at(current_input).at(id_to);

    // for (; current_output != id_to; current_input = current_output) { //std::numeric_limits<unsigned>::max()
    //     output.push_back(nodes_.at(current_output));
    // }

    if (current_output == id_to) {
        output.push_back(nodes_.at(id_to)); //could be pushed back anyway to calculate the shortest distance along the path
        return output;
    }

    return output;
}

std::vector<Node*> Graph::shortest_path_floyd_warshall(Node* node_from, Node* node_to) {
    if (node_from == nullptr) {
        throw std::invalid_argument("node_from is nullptr");
    }
    if (node_to == nullptr) {
        throw std::invalid_argument("node_from is nullptr");
    }
    unsigned id_from = node_from->id;
    unsigned id_to = node_to->id;
    return shortest_path_floyd_warshall(id_from, id_to);
}

std::vector<Node*> Graph::compute_dijkstra_path(unsigned id_from, unsigned id_to) {
    //could combine both of these error messages into one
    if (id_from >= total_nodes_) {
        throw std::invalid_argument("id_from:  " + std::to_string(id_from) + " is out of range of total_nodes_: " + std::to_string(total_nodes_));
    }
    if (id_to >= total_nodes_) {
        throw std::invalid_argument("id_to:  " + std::to_string(id_to) + " is out of range of total_nodes_: " + std::to_string(total_nodes_));
    }
    std::vector<Connection> output; //not sure if returning an empty vector here is the best option that is available at the moment
    std::vector<Node*> nodes;

    if (id_to == id_from) {
        nodes.push_back(nodes_.at(id_from));
        return nodes;
    }

    int n = total_nodes_;

    unsigned starting_vertex = id_from;

    std::vector<double> adjacency_list = graph_.at(id_from);
    std::vector<unsigned> predecessor_list = predecessor_.at(id_from);

    std::vector<Connection> priority_queue;
    std::vector<bool> visited(total_nodes_, false);

    //add all nodes to the priority queue
    for (unsigned id_next = 0; id_next < total_nodes_; id_next++) {
        Connection connection{id_from, id_next, graph_.at(id_from).at(id_next)};
        priority_queue.push_back(connection);
    }

    std::make_heap(priority_queue.begin(), priority_queue.end());

    //repeat n times: (from the cs225 lecture slides for prim's algorithm)
    for (size_t i = 0; i < total_nodes_; i++) { //for every node in the graph
        //remove top node from the priority queue, and store it as "top"
        Connection top = priority_queue.at(0);
        // std::cout << top.print() << std::endl;
        visited.at(top.id_to) = true; //and mark top as visited in constant time
        output.push_back(top);
        if (top.id_to == id_to) {
            break; //this is the shortest path as there can't be any negative distances
        }
        priority_queue.erase(priority_queue.begin());
        std::make_heap(priority_queue.begin(), priority_queue.end());

        //go through all of the neighbors of top, not in visited
        unsigned current_id = top.id_to;
        // if (!visited.at(current_id)) {
            for (unsigned id_next = 0; id_next < total_nodes_; id_next++) { //can replace this with adjacency list, currently this traversal is O(n)
                Connection connection{current_id, id_next, graph_.at(current_id).at(id_next)};
                
                //if loop, update priority if less than connection
                for (unsigned k = 0; k < priority_queue.size(); k++) {
                    Connection& check = priority_queue.at(k);
                    if (check.id_to == id_next) {
                        if (connection > check) { //operator is flipped to make a min heap
                            check.id_from = connection.id_from;
                            check.distance += connection.distance;
                            std::make_heap(priority_queue.begin(), priority_queue.end());
                        }
                        break;
                    }
                }

            }

        // }

    }

    for (const Connection& connection : output) {
        nodes.push_back(nodes_.at(connection.id_to));
    }

    return nodes;
}

std::vector<Node*> Graph::compute_dijkstra_path(Node* node_from, Node* node_to) {
    if (node_from == nullptr) {
        throw std::invalid_argument("node_from is nullptr");
    }
    if (node_from == nullptr) {
        throw std::invalid_argument("node_to is nullptr");
    }
    unsigned id_from = node_from->id;
    unsigned id_to = node_from->id;
    return compute_dijkstra_path(id_from, id_to);
}

//getters
std::vector<std::vector<double>> Graph::get_graph() const { return graph_; }
std::vector<std::vector<unsigned>> Graph::get_predecessor() const { return predecessor_; }
std::vector<std::vector<double>> Graph::get_floyd_warshall() const { return floyd_warshall_; }
std::vector<std::vector<double>> Graph::get_heuristic() const { return heuristic_; }
std::vector<Node*> Graph::get_nodes() const { return nodes_; }

unsigned Graph::get_total_nodes() const { return total_nodes_; }
unsigned Graph::get_total_edges() const { return total_edges_; }


std::string Graph::print_graph() {
    return this->print(graph_);
}
std::string Graph::print_predecessors() {
    std::string output;
    // std::cout << '\n' << std::endl;
    // output += '\n';
    for (const std::vector<unsigned>& vect : predecessor_) {
        for (unsigned predecessor : vect) {
            // std::cout << predecessor << " ";
            if (predecessor != std::numeric_limits<unsigned>::max()) {
                output += std::to_string(predecessor) + " ";
            } else {
                output += "max ";
            }
        }
        // std::cout << '\n' << std::endl;
        output += '\n';
    }
    // std::cout << std::endl;
    // output += '\n';
    return output;
}

std::string Graph::print_nodes() {
    std::string output;
    // std::cout << '\n' << std::endl;
    // output += '\n';
    for (Node* node : nodes_) {
        if (node != nullptr) {
            // std::cout << "[" << node->longitude << " " << node->longitude << "] ";
            output += "[" + std::to_string(node->latitude) + " " + std::to_string(node->longitude) + "] ";
        } else {
            // std::cout << "null ";
            output += "null ";
        }
    }
    // std::cout << std::endl;
    // output += '\n';
    return output;
}

std::string Graph::print_floyd_warshall() {
    return this->print(floyd_warshall_);
}

std::string Graph::print_heuristic() {
    return this->print(heuristic_);
}

std::string Graph::print(const std::vector<std::vector<double>>& graph) {
    std::string output;
    // std::cout << '\n' << std::endl;
    // output += '\n';
    for (const std::vector<double>& vect : graph) {
        for (double distance : vect) {
            // if (node_ptr != -1) {
                // std::cout << distance << " ";
                if (distance != std::numeric_limits<double>::max()) {
                    output += std::to_string(distance) + " ";
                } else {
                    output += "max ";
                }
            // } else {
            //     std::cout << "null\t";
            // }
        }
        // std::cout << '\n' << std::endl;
        output += '\n';
    }
    // std::cout << std::endl;
    // output += '\n';
    return output;
}

void Graph::print_all_vars() {
    std::cout << "\ngraph_\n" << this->print_graph() << std::endl;
    std::cout << "\npredecessor_\n" << this->print_predecessors() << std::endl;
    std::cout << "\nheuristic_\n" << this->print_heuristic() << std::endl;
    std::cout << "\nfloyd_warshall_\n" << this->print_floyd_warshall() << std::endl;
    std::cout << "\nnodes_ (latitude, longitude)\n" << this->print_nodes() << std::endl;
}

std::string Node::print() const {
    std::string output;
    output += std::to_string(this->id) + " " + std::to_string(this->latitude) + " " + std::to_string(this->longitude) + " ";
    return output;
}

bool Connection::operator<(const Connection& other) const {
    return this->distance > other.distance;
}

bool Connection::operator>(const Connection& other) const {
    return this->distance < other.distance;
}

std::string Connection::print() const {
    std::string output;
    output += std::to_string(this->id_from) + " " + std::to_string(this->id_to) + " ";
    if (distance == std::numeric_limits<double>::max()) {
        output += "max";
    } else {
        output += std::to_string(this->distance);
    }
    return output;
}
