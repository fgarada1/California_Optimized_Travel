#include <catch2/catch_test_macros.hpp>
#include "Graph.h"
#include <iostream>

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
    TEST_CASE("test nodes format error", "[constructor]") {
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        size_t j = 0;
        for (; j < 2; j++) {
            // std::cout << "line: " << j << std::endl;
            for (size_t i = 0; i < 3; i++) {
                std::string input = "../more_test/test_nodes" + std::to_string(j) + std::to_string(i) + ".txt";
                // Graph main_graph(input, "../more_test/test_edges.txt", 6, 8); //total_nodes and total_edges not supposed to cause an error
                REQUIRE_THROWS( Graph(input, "../more_test/test_edges.txt", ktotal_nodes, ktotal_edges) );
            }
        }
        j = 3;
        for (size_t i = 0; i < 3; i++) {
            std::string input = "../more_test/test_nodes" + std::to_string(j) + std::to_string(i) + ".txt";
            // Graph main_graph(input, "../more_test/test_edges.txt", 6, 8); //total_nodes and total_edges not supposed to cause an error
            REQUIRE_THROWS( Graph(input, "../more_test/test_edges.txt", ktotal_nodes, ktotal_edges) );
        }
        j = ktotal_nodes - 1; //6 - 1 = 5
        for (size_t i = 0; i < 3; i++) {
            std::string input = "../more_test/test_nodes" + std::to_string(j) + std::to_string(i) + ".txt";
            // Graph main_graph(input, "../more_test/test_edges.txt", 6, 8); //total_nodes and total_edges not supposed to cause an error
            REQUIRE_THROWS( Graph(input, "../more_test/test_edges.txt", ktotal_nodes, ktotal_edges) );
        }

    }
    TEST_CASE("test edges format error", "[constructor]") {
        const size_t ktotal_nodes = 6;
        const size_t ktotal_edges = 8;
        // std::cout << "test edges" << std::endl;
        size_t j = 0;
        for (; j < 2; j++) {
            // std::cout << "line: " << j << std::endl;
            for (size_t i = 0; i < 4; i++) {
                std::string input = "../more_test/test_edges" + std::to_string(j) + std::to_string(i) + ".txt";
                // Graph main_graph("../more_test/test_nodes.txt", input, 6, 8); //total_nodes and total_edges not supposed to cause an error
               REQUIRE_THROWS( Graph("../more_test/test_nodes.txt", input, ktotal_nodes, ktotal_edges) );
            }
        }
        j = 5;
        for (size_t i = 0; i < 4; i++) {
            std::string input = "../more_test/test_edges" + std::to_string(j) + std::to_string(i) + ".txt";
            // Graph main_graph("../more_test/test_nodes.txt", input, 6, 8); //total_nodes and total_edges not supposed to cause an error
            REQUIRE_THROWS( Graph("../more_test/test_nodes.txt", input, ktotal_nodes, ktotal_edges) );
        }
        j = ktotal_edges - 1; //8 - 1 = 7
        for (size_t i = 0; i < 4; i++) {
            std::string input = "../more_test/test_edges" + std::to_string(j) + std::to_string(i) + ".txt";
            // Graph main_graph("../more_test/test_nodes.txt", input, 6, 8); //total_nodes and total_edges not supposed to cause an error
            REQUIRE_THROWS( Graph("../more_test/test_nodes.txt", input, ktotal_nodes, ktotal_edges) );
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
        Graph main_graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(graph.size() == total_nodes);
        for (const std::vector<double>& vect : graph) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        } //copied from floyd_warshall's initialization test case
        for (size_t i = 0; i < total_nodes; i++) {
            REQUIRE(graph.at(i).size() == total_nodes);
            for (size_t j = 0; j < total_nodes; j++) {
                double num1 = graph.at(i).at(j);
                if (i == j) {
                    std::cout << "i: " << i << " j: " << j << std::endl;
                    std::cout << "num1: " << num1 << std::endl;
                    std::cout << "(num1 == 0): " << (num1 == 0) << std::endl;
                    REQUIRE(num1 == 0);
                } else {
                    std::cout << "i: " << i << " j: " << j << std::endl;
                    std::cout << "num1: " << num1 << std::endl;
                    std::cout << "(num1 == 0): " << (num1 == 0) << std::endl;
                    REQUIRE(((num1 == (-1.0)) || (num1 > 0)));
                }
            }
        }
        // std::string expected_output = "0.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
        //                             "\n4.000000 0.000000 2.000000 -1.000000 -1.000000 "
        //                             "\n1.000000 -1.000000 0.000000 -1.000000 -1.000000 "
        //                             "\n-1.000000 -1.000000 -1.000000 0.000000 -1.000000 "
        //                             "\n-1.000000 -1.000000 -1.000000 2.000000 0.000000 \n";
        std::string expected_output = "0.000000 4.000000 1.000000 max max "
                                    "\nmax 0.000000 max max max "
                                    "\nmax 2.000000 0.000000 max max "
                                    "\nmax max max 0.000000 2.000000 "
                                    "\nmax max max max 0.000000 \n";
        
        REQUIRE(main_graph.print_graph() == expected_output);
    }
    TEST_CASE("predecessor_ does not contain numbers outside of range total_nodes, and infinity", "[constructor]") {
        Graph main_graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
        auto predecessors = main_graph.get_predecessor();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(predecessors.size() == total_nodes);
        for (const std::vector<unsigned>& vect : predecessors) {
            REQUIRE(vect.size() == total_nodes);
            for (unsigned num : vect) {
                REQUIRE(((num == (static_cast<unsigned>(-1))) || (num < total_nodes))); //num >= 0 && is always true
            }
        }
        std::string expected_output = "0 0 0 max max "
                                    "\nmax 1 max max max "
                                    "\nmax 2 2 max max "
                                    "\nmax max max 3 3 "
                                    "\nmax max max max 4 \n";
        REQUIRE(main_graph.print_predecessors() == expected_output);
    }
    TEST_CASE("check that floyd_warshall_ is the same as graph_ upon initialization", "[constructor]") {
        Graph main_graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
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
                double num1 = graph.at(i).at(j);
                double num2 = floyd_warshall.at(i).at(j);
                if (i == j) {
                    std::cout << "i: " << i << " j: " << j << std::endl;
                    std::cout << "num1: " << num1 << std::endl;
                    std::cout << "(num1 == 0): " << (num1 == 0) << std::endl;
                    std::cout << "num2: " << num2 << std::endl;
                    std::cout << "(num2 == 0): " << (num2 == 0) << std::endl;
                    REQUIRE(num1 == 0);
                    REQUIRE(num2 == 0);
                } else {
                    std::cout << "i: " << i << " j: " << j << std::endl;
                    std::cout << "num1: " << num1 << std::endl;
                    std::cout << "(num1 == 0): " << (num1 == 0) << std::endl;
                    std::cout << "num2: " << num2 << std::endl;
                    std::cout << "(num2 == 0): " << (num2 == 0) << std::endl;
                    REQUIRE(((num1 == (-1.0)) || (num1 > 0)));
                    REQUIRE(((num2 == (-1.0)) || (num2 > 0)));
                }
                REQUIRE(num1 == num2);
            }
        }
        //could check the matrices themselves together, but this also works so I think this is fine for this scale
        // std::string expected_output = "0.000000 -1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
        //                            "\n20.100000 0.000000 -1.000000 -1.000000 -1.000000 2.700000 "
        //                            "\n20.200000 2.300000 0.000000 -1.000000 -1.000000 0.100000 "
        //                            "\n-1.000000 -1.000000 2.400000 0.000000 -1.000000 -1.000000 "
        //                            "\n-1.000000 -1.000000 -1.000000 2.500000 0.000000 2.600000 "
        //                            "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 0.000000 \n";
        std::string expected_output = "0.000000 4.000000 1.000000 max max "
                                    "\nmax 0.000000 max max max "
                                    "\nmax 2.000000 0.000000 max max "
                                    "\nmax max max 0.000000 2.000000 "
                                    "\nmax max max max 0.000000 \n";
        REQUIRE(main_graph.print_graph() == expected_output);
        REQUIRE(main_graph.print_floyd_warshall() == expected_output);
        REQUIRE(main_graph.get_graph() == main_graph.get_floyd_warshall());
    }
    TEST_CASE("check that heuristic is initialized correctly", "[constructor]") {
        Graph main_graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        auto heuristic = main_graph.get_heuristic();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(heuristic.size() == total_nodes);
        for (const std::vector<double>& vect : heuristic) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE((num >= 0));
            }
        }
        REQUIRE(heuristic.size() == total_nodes);
        // for (size_t i = 0; i < total_nodes; i++) {
        //     REQUIRE(heuristic.at(i).size() == total_nodes);
        //     for (size_t j = 0; j < total_nodes; j++) {
        //         // int num1 = graph.at(i).at(j);
        //         // int num2 = floyd_warshall.at(i).at(j);
        //         // REQUIRE(((num1 == (-1.0)) || (num1 >= 0)));
        //         // REQUIRE(((num2 == (-1.0)) || (num2 >= 0)));
        //         // REQUIRE(num1 == num2);
        //         double num = heuristic.at(i).at(j);
        //         REQUIRE((num >= 0));
        //     }
        // }
        //TODO //done? not checked but I assume it's correct
        //make this right
        // std::string expected_output = "0.000000 -1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
        //                            "\n20.100000 0.000000 -1.000000 -1.000000 -1.000000 2.700000 "
        //                            "\n20.200000 2.300000 0.000000 -1.000000 -1.000000 0.100000 "
        //                            "\n-1.000000 -1.000000 2.400000 0.000000 -1.000000 -1.000000 "
        //                            "\n-1.000000 -1.000000 -1.000000 2.500000 0.000000 2.600000 "
        //                            "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 0.000000 \n";
        // std::string expected_output     = "-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
        //                                 "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
        //                                 "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
        //                                 "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 "
        //                                 "\n-1.000000 -1.000000 -1.000000 -1.000000 -1.000000 \n";
        std::string expected_output     = "0.000000 2.000000 1.414214 3.000000 3.605551 "
                                        "\n2.000000 0.000000 1.414214 1.000000 2.236068 "
                                        "\n1.414214 1.414214 0.000000 2.236068 2.236068 "
                                        "\n3.000000 1.000000 2.236068 0.000000 2.000000 "
                                        "\n3.605551 2.236068 2.236068 2.000000 0.000000 \n";
                                        
        REQUIRE(main_graph.print_heuristic() == expected_output);
    }
    TEST_CASE("check that nodes_ is initializated correctly", "[constructor]") {
        Graph main_graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        unsigned total_nodes = main_graph.get_total_nodes();

        REQUIRE(main_graph.get_nodes().size() == total_nodes);
        for (Node* node : main_graph.get_nodes()) {
            REQUIRE(((node != (nullptr)) && (node->id < total_nodes))); //&& (node->id >= 0) is always true
        }

        //could check the matrices themselves together, but this also works so I think this is fine for this scale
        std::string expected_output = "[1.000000 4.000000] [1.000000 2.000000] [2.000000 3.000000] [1.000000 1.000000] [3.000000 1.000000] ";
        REQUIRE(main_graph.print_nodes() == expected_output);
    }
    
// }

//need to add
//constructor vector no nodes are null
//- BFS
//- A* + heuristic check (none are null)
//- Floyd Warshall's


TEST_CASE("BFS_1: small input", "[bfs]") {
    Graph test("../test_nodes.txt", "../test_edges.txt", 11, 11);
    std::vector<Node*> out = test.get_bfs(-121.904167, 41.974556, .006);
    
    std::vector<Node*> ans = {test.get_nodes().at(1), test.get_nodes().at(6)};
    REQUIRE(out == ans);
}

TEST_CASE("BFS_2: invalid input", "[bfs]") {
    Graph test("../test_nodes.txt", "../test_edges.txt", 11, 11);
    // invalid input pair, but valid distance
    std::vector<Node*> out = test.get_bfs(90, 4, .006);
    REQUIRE(out == std::vector<Node*>());
}

TEST_CASE("BFS_3: invalid, distance too small", "[bfs]") {
    Graph test("../test_nodes.txt", "../test_edges.txt", 11, 11);
    // valid input pair, but too small distance
    std::vector<Node*> out = test.get_bfs(-121.904167, 41.974556, .0000006);
    REQUIRE(out == std::vector<Node*>());
}

TEST_CASE("BFS_4: bfs helper valid test", "[bfs]") {
    Graph test("../test_nodes.txt", "../test_edges.txt", 11, 11);
    // valid input pair, but too small distance
    std::vector<unsigned> out = test.bfs_helper(0, .006);
    std::vector<unsigned> ans = {1, 6};

    REQUIRE(out == ans);
}


    //check that floyd_walrshall works properly
    TEST_CASE("floyd_warshall functions as intended", "[floyd_walker]") {
        Graph main_graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        auto floyd_warshall = main_graph.get_floyd_warshall();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(graph.size() == total_nodes);
        REQUIRE(floyd_warshall.size() == total_nodes);
        for (const std::vector<double>& vect : graph) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        } //copied from floyd_warshall's initialization test case
        for (size_t i = 0; i < total_nodes; i++) {
            REQUIRE(floyd_warshall.at(i).size() == total_nodes);
            for (size_t j = 0; j < total_nodes; j++) {
                double num1 = graph.at(i).at(j);
                if (i == j) {
                    std::cout << "i: " << i << " j: " << j << std::endl;
                    std::cout << "num1: " << num1 << std::endl;
                    std::cout << "(num1 == 0): " << (num1 == 0) << std::endl;
                    REQUIRE(num1 == 0);
                } else {
                    std::cout << "i: " << i << " j: " << j << std::endl;
                    std::cout << "num1: " << num1 << std::endl;
                    std::cout << "(num1 == 0): " << (num1 == 0) << std::endl;
                    REQUIRE(((num1 == (-1.0)) || (num1 > 0)));
                }
            }
        }
        main_graph.compute_floyd_warshall();
        std::string expected_output = "0.000000 3.000000 1.000000 max max "
                                    "\nmax 0.000000 max max max "
                                    "\nmax 2.000000 0.000000 max max "
                                    "\nmax max max 0.000000 2.000000 "
                                    "\nmax max max max 0.000000 \n";
        REQUIRE(main_graph.print_floyd_warshall() == expected_output);

        std::string expected_predecessor_output = "0 2 0 max max "
                                                "\nmax 1 max max max "
                                                "\nmax 2 2 max max "
                                                "\nmax max max 3 3 "
                                                "\nmax max max max 4 \n";
        REQUIRE(main_graph.print_predecessors() == expected_predecessor_output);
    }

    //check that A* works properly
    TEST_CASE("A* functions as intended", "[astar]") {
        Graph main_graph("../more_test/example_nodes4.txt", "../more_test/example_edges4.txt", 5, 4); //not supposed to cause an error
        auto graph = main_graph.get_graph();
        unsigned total_nodes = main_graph.get_total_nodes();
        REQUIRE(graph.size() == total_nodes);
        for (const std::vector<double>& vect : graph) {
            REQUIRE(vect.size() == total_nodes);
            for (double num : vect) {
                REQUIRE(((num == (-1.0)) || (num >= 0)));
            }
        }
        std::vector<Node*> nodes = main_graph.compute_astar_path(0, 1);
        std::string expected_output = "0 1.000000 4.000000 "
                                    "\n2 2.000000 3.000000 "
                                    "\n1 1.000000 2.000000 \n";
        REQUIRE(main_graph.print_nodes(nodes) == expected_output);

    }

