#include <vector>
#include <string>
#include <map>

class Graph {
    public:
    Graph(const std::string& filename_nodes, const std::string& filename_edges);


    private:
    struct Node {
        int id;
        double latitude;
        double longitude;
    };
    struct Connection {
        Node node;
        double distance;
    };

    std::map<Node, std::vector<Connection>> graph;
};
