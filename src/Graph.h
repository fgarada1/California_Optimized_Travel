#include <vector>
#include <string>
#include <map>

class Graph {
    public:
    Graph(const std::string& filename_nodes, const std::string& filename_edges, int total_nodes);

    void print_graph();
    void print_predecessors();

    ~Graph();


    private:
    struct Node {
        unsigned id;
        double latitude;
        double longitude;
    };
    struct Connection {
        Node node;
        double distance;
    };

    void print(const std::vector<std::vector<Node*>>& graph);

    std::vector<std::vector<Node*>> graph_;
    std::vector<std::vector<int>> predecessor_;
};

