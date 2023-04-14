// Po-Shen Lee
// Apr 14
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


void test_graph_is_reachable() {
    graph_t *g = create_graph();
    graph_add_node(g, 0);
    graph_add_node(g, 1);
    graph_add_node(g, 2);
    graph_add_node(g, 3);

    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);

    printf("Test graph_is_reachable: ");
    if (graph_is_reachable(g, 0, 3) == 1) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    free_graph(g);
}

void test_graph_has_cycle() {
    graph_t *g = create_graph();
    graph_add_node(g, 0);
    graph_add_node(g, 1);
    graph_add_node(g, 2);
    graph_add_node(g, 3);

    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 0);

    printf("Test graph_has_cycle: ");
    if (graph_has_cycle(g) == 1) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    free_graph(g);
}

void test_graph_print_path() {
    graph_t *g = create_graph();
    graph_add_node(g, 0);
    graph_add_node(g, 1);
    graph_add_node(g, 2);
    graph_add_node(g, 3);
    graph_add_node(g, 4);

    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 2, 4);

    printf("Test graph_print_path: ");
    if (graph_print_path(g, 0, 4) == 1) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    free_graph(g);
}

int main(int argc, const char * argv[]) {

    test_graph_is_reachable();
    test_graph_has_cycle();
    test_graph_print_path();
    return 0;
}