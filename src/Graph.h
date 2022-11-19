#include <vector>
#include <string>
#include <map>

class Graph {
    public:
    //initalizes all member variables, does not apply any algorithms except for the heuristic for the A* algorithm
    Graph(const std::string& filename_nodes, const std::string& filename_edges, unsigned total_nodes, unsigned total_edges);

    //prints the adjacency matrix for graph_ (the adjacancy matrix representation of the road network)
    void print_graph();
    //prints the contents of predecesor_, for use in floyd_warshall's algorithm
    void print_predecessors();

    //deconstructor for all member variables in the graph, deletes new nodes (if there are any being used in the current graph)
    ~Graph();


    private:
    struct Node {
        unsigned id;
        double latitude;
        double longitude;
    };
    struct Connection {
        unsigned id_from;
        unsigned id_to;
        double distance;
    };

    void print(const std::vector<std::vector<Node*>>& graph);

    //initial graphs
    std::vector<std::vector<double>> graph_; //the adjacency matrix representtation of the graph network, each entry represents the one way distance from col to row
    std::vector<std::vector<unsigned>> predecessor_; //the predecessor graph stored for floyd_warshall's algorithm, each entry represents the predecessor to go to from row to get to col in the end

    //algorithms
    std::vector<std::vector<double>> floyd_warshall_; //stems from a copy of graph_ upon initialization, stores one way shortest distance from col to row, based on all possible paths in the graph
    std::vector<std::vector<double>> heuristic_; //(based on total geographical distance between nodes, direction does not matter here)

    //vector (of nodes)
    std::vector<Node> nodes_; //vector of nodes stored to calculate the heuristic storing adjacency matrix for the A* algorithm

    unsigned total_nodes_;
    unsigned total_edges_;
};
