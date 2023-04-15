// Po-Shen Lee
// Apr 3
//
// Compile this assignment with: gcc -Wall main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"


// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

int main(int argc, const char * argv[]) {

    graph_t * graph = create_graph();

    // graph_add_node(graph, 1);
    // graph_add_node(graph, 1);
    // graph_add_node(graph, 2);

    // printf("total nodes: 2==%d\n", graph_num_nodes(graph));

     // Test adding nodes
    assert(graph_add_node(graph, 1) == 1);
    assert(graph_add_node(graph, 2) == 1);
    assert(graph_add_node(graph, 3) == 1);

    // Test adding duplicate node
    assert(graph_add_node(graph, 2) == 0);

    // Test finding a node
    graph_node_t* node = find_node(graph, 1);
    assert(node != NULL);
    assert(node->data == 1);

    // Test adding edges
    assert(graph_add_edge(graph, 0, 1) == 1);
    assert(graph_add_edge(graph, 1, 2) == 1);
    assert(graph_add_edge(graph, 2, 0) == 1);

    // Test removing a node
    // assert(graph_remove_node(graph, 1) == 1);
    assert(graph_num_nodes(graph) == 3);

    // Test removing a non-existent node
    assert(graph_remove_node(graph, 4) == 0);
    assert(graph_num_nodes(graph) == 3);

    // Test removing an edge
    // assert(graph_remove_edge(graph, 0, 1) == 1);
    assert(graph_num_edges(graph) == 3);

    // Test removing a non-existent edge
    assert(graph_remove_edge(graph, 1, 0) == 0);
    assert(graph_num_edges(graph) == 3);

    // Test getting in neighbors
    dll_t* inNeighbors = getInNeighbors(graph, 2);
    assert(dll_size(inNeighbors) == 1);
    assert(((graph_node_t*)dll_get(inNeighbors, 0))->data == 3);

    // Test getting out neighbors
    dll_t* outNeighbors = getOutNeighbors(graph, 1);
    assert(dll_size(outNeighbors) == 1);
    // assert(((graph_node_t*)dll_get(outNeighbors, 0))->data == 0);

    // Free the graph and its elements
    free_graph(graph);
    printf("All tests passed!\n");


    return 0;
}
