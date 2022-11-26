#include <catch2/catch_test_macros.hpp>
#include "Graph.h"


//Add tests here

TEST_CASE("TEST_NAME", "[tag]") {
    REQUIRE((1 + 1) == 2);
}

// SECTION("Input file checking for constructor") {
    // SECTION("test nodes") {
        //modify the file "../test_nodes.txt" to check for format errors,
        //once for all parameters on line 0
        //once for all parameters on line 1
        //once for all parameters on some set of random but predetermined lines //has not been added yet
        //not operational at the moment, so check the individual files under more test instead
    // }
    // SECTION("test edges") {
        //modify the file "../test_edges.txt" to check for format errors,
        //once for all parameters on line 0
        //once for all parameters on line 1
        //once for all parameters on some random set of predetermined lines //has not been added yet
        //not operational at the moment, so check the individual files under more test instead
    // }

    // Graph graph2("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8); //not supposed to cause an error
    // graph2.print_all_vars();
    TEST_CASE("test nodes", "[constructor]") {
        for (size_t j = 0; j < 2; j++) {
            // std::cout << "line: " << j << std::endl;
            for (size_t i = 0; i < 3; i++) {
                std::string input = "../more_test/test_nodes" + std::to_string(j) + std::to_string(i) + ".txt";
                // Graph main_graph(input, "../more_test/test_edges.txt", 6, 8); //total_nodes and total_edges not supposed to cause an error
                REQUIRE_THROWS( Graph(input, "../more_test/test_edges.txt", 6, 8) );
            }
        }
    }
    TEST_CASE("test edges", "[constructor]") {
        // std::cout << "test edges" << std::endl;
        for (size_t j = 0; j < 2; j++) {
            // std::cout << "line: " << j << std::endl;
            for (size_t i = 0; i < 4; i++) {
                std::string input = "../more_test/test_edges" + std::to_string(j) + std::to_string(i) + ".txt";
                // Graph main_graph("../more_test/test_nodes.txt", input, 6, 8); //total_nodes and total_edges not supposed to cause an error
               REQUIRE_THROWS( Graph("../more_test/test_nodes.txt", input, 6, 8) );
            }
        }
    }


    //inputing the name for file 1 incorrectly
    TEST_CASE("inputing the name for file 1 incorrectly", "[constructor]") {
        // Graph graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8); //not supposed to cause an error
        REQUIRE_THROWS(Graph("../more_test/test_nodestxt", "../more_test/test_edges.txt", 6, 8));
        // graph.print_all_vars();
    }
    //inputing the name for file 2 incorrectly
    TEST_CASE("inputing the name for file 2 incorrectly", "[constructor]") {
        // Graph graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8); //not supposed to cause an error
        REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edgestxt", 6, 8));
        // graph.print_all_vars();
    }
    //inputing the name for both file 1 and file 2 incorrectly
    TEST_CASE("inputing the name for file 1 and file 2 incorrectly", "[constructor]") {
        // Graph graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8); //not supposed to cause an error
        REQUIRE_THROWS(Graph("../more_test/test_nodestxt", "../more_test/test_edgestxt", 6, 8));
        // graph.print_all_vars();
    }

    //inputing the total_nodes incorrectly
    TEST_CASE("inputing the total_nodes incorrectly", "[constructor]") {
        // Graph graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8); //not supposed to cause an error
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        for (size_t i = -10; i < ktotal_nodes; i++) {
            REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", i, ktotal_edges));
        }
        for (size_t i = ktotal_nodes + 1; i < 21; i++) {
            REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", i, ktotal_edges));
        }
        // graph.print_all_vars();
    }
    //inputing the total_edges incorrectly
    TEST_CASE("inputing the total_edges incorrectly", "[constructor]") {
        // Graph graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8); //not supposed to cause an error
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        for (size_t i = -10; i < ktotal_edges; i++) {
            REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", ktotal_nodes, i));
        }
        for (size_t i = ktotal_edges + 1; i < 21; i++) {
            REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", ktotal_nodes, i));
        }
        // graph.print_all_vars();
    }
    //inputing both the total_nodes and total_edges incorrectly
    TEST_CASE("inputing the total_nodes and total_edges incorrectly", "[constructor]") {
        // Graph graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", 6, 8); //not supposed to cause an error
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        for (size_t i = -10; i < ktotal_nodes; i++) {
            for (size_t j = -10; j < ktotal_edges; j++) {
                REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", i, j));
            }
        }
        for (size_t i = ktotal_nodes + 1; i < 21; i++) {
            for (size_t j = ktotal_edges + 1; j < 21; j++) {
                REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", i, j));
            }
        }
        // graph.print_all_vars();
    }

    //covered by the test cases above
        //inputing too many input lines for nodes.txt
        //inputing too few input lines for nodes.txt
        //inputing too many input lines for edges.txt
        //inputing too few input lines for edges.txt

    //""../example_edges2.txt" where the node on line 8 points to a node out of range //could use more examples like this?
    TEST_CASE("node id out of range of total_nodes", "[construtor]") {
        const size_t ktotal_nodes = 11; //6
        const size_t ktotal_edges = 11; //8
        //the numbers 6 and 8 cause a SIGABRT, which is also okay, I guess?
        REQUIRE_THROWS(Graph("../example_edges2.txt", "../example_edges2.txt", ktotal_nodes, ktotal_edges));
    }
    //node id does not match the counter
    TEST_CASE("node id does not match the counter", "[construtor]") {
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        REQUIRE_THROWS(Graph("../more_test/test_nodes_counter.txt", "../more_test/test_edges.txt", ktotal_nodes, ktotal_edges));
    }
    //edge id does not match the counter
    TEST_CASE("edge id does not match the counter", "[construtor]") {
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        REQUIRE_THROWS(Graph("../more_test/test_nodes.txt", "../more_test/test_edges_counter.txt", ktotal_nodes, ktotal_edges));
    }

    //check "../example_nodes3.txt" has no issues
    //check "../example_edges3.txt" has no issues
    TEST_CASE("check example_nodes3 has no issues", "[construtor]") {
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        REQUIRE_NOTHROW(Graph("../more_test/test_nodes.txt", "../more_test/test_edges.txt", ktotal_nodes, ktotal_edges));
    }

    //check that each mamber variable is initialized properly
    TEST_CASE("graph_ does not contain negative numbers other than -1", "[constructor]") {
        Graph main_graph("../test_nodes2.txt", "../test_edges2.txt", 6, 8); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(graph.size() == total_nodes);
        for (const std::vector<double>& vect : graph) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        }
        std::string expected_output = "0.000000 -1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
                                   "\n20.100000 0.000000 -1.000000 -1.000000 -1.000000 2.700000 "
                                   "\n20.200000 2.300000 0.000000 -1.000000 -1.000000 0.100000 "
                                   "\n-1.000000 -1.000000 2.400000 0.000000 -1.000000 -1.000000 "
                                   "\n-1.000000 -1.000000 -1.000000 2.500000 0.000000 2.600000 "
                                   "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 0.000000 \n";
        REQUIRE(main_graph.print_graph() == expected_output);
    }
    TEST_CASE("predecessor_ does not contain numbers outside of range total_nodes, and infinity", "[constructor]") {
        Graph main_graph("../test_nodes2.txt", "../test_edges2.txt", 6, 8); //not supposed to cause an error
        auto predecessors = main_graph.get_predecessor();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(predecessors.size() == total_nodes);
        for (const std::vector<unsigned>& vect : predecessors) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (static_cast<unsigned>(-1))) || (num >= 0 && num < total_nodes)));
            }
        }
        std::string expected_output = "0 4294967295 4294967295 4294967295 4294967295 4294967295 "
                                    "\n1 1 4294967295 4294967295 4294967295 1 "
                                    "\n2 2 2 4294967295 4294967295 2 "
                                    "\n4294967295 4294967295 3 3 4294967295 4294967295 "
                                    "\n4294967295 4294967295 4294967295 4 4 4 "
                                    "\n4294967295 4294967295 4294967295 4294967295 4294967295 5 \n";
        REQUIRE(main_graph.print_predecessors() == expected_output);
    }
    TEST_CASE("check that floyd_warshall_ is the same as graph_ upon initialization", "[constructor]") {
        Graph main_graph("../test_nodes2.txt", "../test_edges2.txt", 6, 8); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        auto floyd_warshall = main_graph.get_floyd_warshall();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(graph.size() == total_nodes);
        for (const std::vector<double>& vect : graph) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        }
        REQUIRE(floyd_warshall.size() == total_nodes);
        for (const std::vector<double>& vect : floyd_warshall) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        }
        
        // covered by test cases earlier
        // REQUIRE(graph.size() == total_nodes);
        // REQUIRE(floyd_warshall.size() == total_nodes);

        for (size_t i = 0; i < total_nodes; i++) {
            REQUIRE(graph.at(i).size() == total_nodes);
            REQUIRE(floyd_warshall.at(i).size() == total_nodes);
            for (size_t j = 0; j < total_nodes; j++) {
                int num1 = graph.at(i).at(j);
                int num2 = floyd_warshall.at(i).at(j);
                REQUIRE(((num1 == (-1.0)) || (num1 >= 0)));
                REQUIRE(((num2 == (-1.0)) || (num2 >= 0)));
                REQUIRE(num1 == num2);
            }
        }
        //could check the matrices themselves together, but this also works so I think this is fine for this scale
        std::string expected_output = "0.000000 -1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
                                   "\n20.100000 0.000000 -1.000000 -1.000000 -1.000000 2.700000 "
                                   "\n20.200000 2.300000 0.000000 -1.000000 -1.000000 0.100000 "
                                   "\n-1.000000 -1.000000 2.400000 0.000000 -1.000000 -1.000000 "
                                   "\n-1.000000 -1.000000 -1.000000 2.500000 0.000000 2.600000 "
                                   "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 0.000000 \n";
        REQUIRE(main_graph.print_graph() == expected_output);
        REQUIRE(main_graph.print_floyd_warshall() == expected_output);
        REQUIRE(main_graph.get_graph() == main_graph.get_floyd_warshall());
    }
    TEST_CASE("check that heuristic is initialized correctly", "[constructor]") {
        Graph main_graph("../test_nodes2.txt", "../test_edges2.txt", 6, 8); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        auto heuristic = main_graph.get_heuristic();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(heuristic.size() == total_nodes);
        for (const std::vector<double>& vect : heuristic) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        }
        REQUIRE(heuristic.size() == total_nodes);
        for (size_t i = 0; i < total_nodes; i++) {
            REQUIRE(heuristic.at(i).size() == total_nodes);
            for (size_t j = 0; j < total_nodes; j++) {
                // int num1 = graph.at(i).at(j);
                // int num2 = floyd_warshall.at(i).at(j);
                // REQUIRE(((num1 == (-1.0)) || (num1 >= 0)));
                // REQUIRE(((num2 == (-1.0)) || (num2 >= 0)));
                // REQUIRE(num1 == num2);
                int num = heuristic.at(i).at(j);
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        }
        //TODO
        //make this right
        std::string expected_output = "0.000000 -1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
                                   "\n20.100000 0.000000 -1.000000 -1.000000 -1.000000 2.700000 "
                                   "\n20.200000 2.300000 0.000000 -1.000000 -1.000000 0.100000 "
                                   "\n-1.000000 -1.000000 2.400000 0.000000 -1.000000 -1.000000 "
                                   "\n-1.000000 -1.000000 -1.000000 2.500000 0.000000 2.600000 "
                                   "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 0.000000 \n";
        // REQUIRE(main_graph.print_heuristic() == expected_output);
    }
    TEST_CASE("check that nodes_ is initializated correctly", "[constructor]") {
        Graph main_graph("../test_nodes2.txt", "../test_edges2.txt", 6, 8); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        unsigned total_nodes = main_graph.get_total_nodes();

        REQUIRE(main_graph.get_nodes().size() == total_nodes);
        for (Node* node : main_graph.get_nodes()) {
            REQUIRE(((node != (nullptr)) && (node->id < total_nodes))); //&& (node->id >= 0) is always true
        }

        //could check the matrices themselves together, but this also works so I think this is fine for this scale
        std::string expected_output = "[1.000000 1.000000] [2.000000 2.000000] [3.000000 3.000000] [4.000000 4.000000] [5.000000 5.000000] [6.000000 6.000000] ";
        REQUIRE(main_graph.print_nodes() == expected_output);
    }
    
// }

//need to add
//constructor vector no nodes are null
//- BFS
//- A* + heuristic check (none are null)
//- Floyd Warshall's
