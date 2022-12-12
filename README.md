# California_Optimized_Travel
Given a start and end point in the state of California from the user, we will find the most optimal route to travel the distance between the points using either the amount of roads or the geographical distance, based on user preference.

Note: We were unable to run our code on the inital dataset, so we used a smaller dataset of the city of Oldenburg.

Documents:
Our Team Project Proposal, Team Contract, and written report can be found under the documents folder.

Code:
All algorithms can be accessed from main.cpp.
To first initialize the graph, create a graph object in main.cpp and link the appropriate files as shown:

                nodes.txt          edges.txt     #nodes #edges
                
Graph graph("../ol_nodes.txt", "../ol_edges.txt", 6105, 7035); //not supposed to cause an error

If you would like to use different files, keep in mind that the max number of nodes that the computer we used can handle is ~17000 nodes, and the max number of edges was around ~16000.

More test examples can be found under the main directory, and in the more_test folder. (Most of the non example test cases (e.g. "test_edges13.txt") in more_test are designed to fail and are used for testing purposes.)

To run the code, first cd to the folder this project is in and enter: 
mkdir build
cd build

If there already exists a build directory, first delete the build directory and then run the commands as shown above.

Then enter:
cmake ..

Now, you are ready to run the code. Each time you make changes to main (or any other part of the code), type:
make
./main

and that should show the results of main.cpp.

If you would like to run tests.cpp, type:
make test
./test

and this should show the result of all of the tests in tests.cpp.



Useful functions:

print_all_vars() - returns a std::string of all of the member variables in the Graph class. Each variable can be printed separately.

print_nodes(const std::vector<Node*>& graph) - takes in a std::vector of Node* objects and prints each node on a new line. This is useful for seeing the results of the algorithms that return a std::vector of Node* objects, such as the astar algorithm

Algorithms:

Floyd Warshall:
- you must run this algorithm before you are able to use shortest_path_floyd_warshall. To see the total matrix, run print_floyd_warshall().
    void compute_floyd_warshall() 

- both of these functions return the shortest path as a std::vector<Node*> from node_from to node_to, based on the floyd warshall's algorithm, if no such path exists, returns a vector with only the starting node
    std::vector<Node*> shortest_path_floyd_warshall(unsigned id_from, unsigned id_to); -takes in an id_from and an id_to
    std::vector<Node*> shortest_path_floyd_warshall(Node* node_from, Node* node_to); -takes in a node_from and a node_to

Dijkstra's:
- both of these functions return the shortest path as a std::vector<Node*> from node_from to node_to, based on the dijkstra's algorithm, if no such path exists, returns a vector with only the starting node
    std::vector<Node*> compute_dijkstra_path(unsigned id_from, unsigned id_to); -takes in an id_from and an id_to
    std::vector<Node*> compute_dijkstra_path(Node* node_from, Node* node_to); -takes in a node_from and a node_to

A*:
-you must run one of these functions before you can use compute_astar_path, the default ran in the constructor is pythagorean distance
-both functions compute the heuristic matrix for use in the A* algorithm, each entry is the geographical distance between col and row, computed using the selected formula
    void compute_heuristic_matrix_haversine();
    void compute_heuristic_matrix_pythagorean_distance();

- both of these functions return the shortest path as a std::vector<Node*> from node_from to node_to, based on the A* algorithm, if no such path exists, returns a vector with only the starting node
    std::vector<Node*> compute_astar_path(unsigned id_from, unsigned id_to); -takes in an id_from and an id_to
    std::vector<Node*> compute_astar_path(Node* node_from, Node* node_to); -takes in a node_from and a node_to

BFS:
-tbd
