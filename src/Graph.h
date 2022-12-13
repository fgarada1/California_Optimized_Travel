#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct Node {
    unsigned id;
    double latitude;
    double longitude;
    std::string print() const;
};
struct Connection {
    unsigned id_from;
    unsigned id_to;
    double distance;
    bool operator<(const Connection& other) const; //flipped to make a min heap
    bool operator>(const Connection& other) const; //flipped to make a min heap
    std::string print() const;
};

class Graph {
    public:
    //initalizes all member variables, does not apply any algorithms except for the heuristic for the A* algorithm
    Graph(const std::string& filename_nodes, const std::string& filename_edges, unsigned total_nodes, unsigned total_edges);
    
    //prints the adjacency matrix for graph_ (the adjacancy matrix representation of the road network)
    std::string print_graph();
    //prints the contents of predecesor_, for use in floyd_warshall's algorithm
    std::string print_predecessors();
    //prints the contents of nodes_, for use in the A* algorithm
    std::string print_nodes();
    //generic 2D print algorithm, for graphs of type std::vector<Node*>
    std::string print_nodes(const std::vector<Node*>& graph);
    //prints the contents of floyd_warshall_, the result of the floyd warshall's algorithm
    std::string print_floyd_warshall();
    //prints the contents of heuristic_, for use in the A* algorithm
    std::string print_heuristic();

    //prints information about all member variables of the graph object
    void print_all_vars();

    //computes and updates the adjacency matrix for floyd_warshall_ using the floyd warshall's algorithm 
    void compute_floyd_warshall();

    //returns the shortest path as a std::vector<Node*> from node_from to node_to, based on the floyd warshall's algorithm, if no such path exists, returns a vector with only the starting node
    std::vector<Node*> shortest_path_floyd_warshall(unsigned id_from, unsigned id_to);
    std::vector<Node*> shortest_path_floyd_warshall(Node* node_from, Node* node_to);

    //returns the shortest path as a std::vector<Node*> from node_from to node_to, based on the dijkstra's algorithm, if no such path exists, returns a vector with only the starting node
    std::vector<Node*> compute_dijkstra_path(unsigned id_from, unsigned id_to);
    std::vector<Node*> compute_dijkstra_path(Node* node_from, Node* node_to);

    //returns the shortest path as a std::vector<Node*> from node_from to node_to, based on the A* algorithm, if no such path exists, returns a vector with only the starting node
    std::vector<Node*> compute_astar_path(unsigned id_from, unsigned id_to);
    std::vector<Node*> compute_astar_path(Node* node_from, Node* node_to);

    //deconstructor for all member variables in the graph, deletes new nodes (if there are any being used in the current graph)
    ~Graph();

    //getters
    std::vector<std::vector<double>> get_graph() const;
    std::vector<std::vector<unsigned>> get_predecessor() const;
    std::vector<std::vector<double>> get_floyd_warshall() const;
    std::vector<std::vector<double>> get_heuristic() const;
    std::vector<Node*> get_nodes() const; //not really const?
    std::vector<Node*> get_bfs(double x, double y, double distance);

    unsigned get_total_nodes() const;
    unsigned get_total_edges() const;

    //computes the heuristic matrix for use in the A* algorithm, each entry is the geographical distance between col and row, computed using the haversine formula
    void compute_heuristic_matrix_haversine();
    //computes the heuristic matrix for use in the A* algorithm, each entry is the geographical distance between col and row, computed using the pythagorean theorem
    void compute_heuristic_matrix_pythagorean_distance();

    std::vector<unsigned> bfs_helper(unsigned start_id, double distance);


    private:


    //uses the haversine formula to return the distance between two nodes
    double haversine(Node* node1, Node* node2);

    //uses the pythagorean formula to return the distance between two nodes
    double pythagorean_distance(Node* node1, Node* node2);

    // //computes and updates the adjacency matrix for floyd_warshall_ using the floyd warshall's algorithm 
    // void compute_floyd_warshall();

    //generic 2D print algorithm, for graphs of type std::vector<std::vector<double>>
    std::string print(const std::vector<std::vector<double>>& graph);


    //initial graphs
    std::vector<std::vector<double>> graph_; //the adjacency matrix representtation of the graph network, each entry represents the one way distance from col to row
    std::vector<std::vector<unsigned>> predecessor_; //the predecessor graph stored for floyd_warshall's algorithm, each entry represents the predecessor to go to from row to get to col in the end

    //algorithms
    std::vector<std::vector<double>> floyd_warshall_; //stems from a copy of graph_ upon initialization, stores one way shortest distance from col to row, based on all possible paths in the graph
    std::vector<std::vector<double>> heuristic_; //(based on total geographical distance between nodes, direction does not matter here)

    //vector (of nodes)
    std::vector<Node*> nodes_; //vector of nodes stored to calculate the heuristic storing adjacency matrix for the A* algorithm
    void createCoordinateMap();
    std::map<std::pair<double, double>, unsigned> coord_to_node_; // used for bfs traversal - key is the x,y coordinate and val is node id. Should be essentially same as node vect
    unsigned total_nodes_;
    unsigned total_edges_;
};
