#include <catch2/catch_test_macros.hpp>


//Add tests here

TEST_CASE("TEST_NAME", "[tag]") {
    REQUIRE((1 + 1) == 2);
}

SECTION("Input file checking for constructor") {
    SECTION("test nodes") {
        //modify the file "../test_nodes.txt" to check for format errors,
        //once for all parameters on line 0
        //once for all parameters on line 1
        //once for all parameters on some set of random but predetermined lines

    }
    SECTION("test edges") {
        //modify the file "../test_edges.txt" to check for format errors,
        //once for all parameters on line 0
        //once for all parameters on line 1
        //once for all parameters on some random set of predetermined lines

    }
    //inputing the name for file 1 incorrectly
    //inputing the name for file 2 incorrectly
    //inputing the name for both file 1 and file 2 incorrectly

    //inputing the total_nodes incorrectly
    //inputing the total_edges incorrectly
    //inputing both the total_nodes and total_edges incorrectly

    //covered by the test cases above
        //inputing too many input lines for nodes.txt
        //inputing too few input lines for nodes.txt
        //inputing too many input lines for edges.txt
        //inputing too few input lines for edges.txt

    //""../example_edges2.txt" where the node on line 8 points to a node out of range //could use more examples like this?
    //node id does not match the counter
    //edge id does not match the counter

    //check "../example_nodes3.txt" has no issues
    //check "../example_edges3.txt" has no issues

    //check that each mamber variable is initialized properly
}

//need to add
//constructor vector no nodes are null
//- BFS
//- A* + heuristic check (none are null)
//- Floyd Warshall's
