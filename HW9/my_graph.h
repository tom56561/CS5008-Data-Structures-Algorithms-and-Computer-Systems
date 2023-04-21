// =================== Support Code =================
// Graph.
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions.
//   - (You may consider using these printf statements to debug, but they 
//      should be removed from your final version)
// ==================================================
#ifndef MY_GRAPH_H
#define MY_GRAPH_H

#include "my_dll.h"
#include "string.h"

typedef struct graph_edge {
    int weight;
    struct graph_node *destination;
} graph_edge_t;

typedef struct graph_node {
    char *city_name;
    int cost;
    struct graph_node *from;
    dll_t *edges;
} graph_node_t;

typedef struct graph {
    dll_t *nodes;
} graph_t;

graph_t *graph_create() {
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->nodes = create_dll();
    return graph;
}

void graph_add_node(graph_t *graph, const char *city_name) {
    graph_node_t *node = (graph_node_t *)malloc(sizeof(graph_node_t));
    node->city_name = strdup(city_name);
    node->cost = -1;
    node->from = NULL;
    node->edges = create_dll();
    dll_push_back(graph->nodes, node);
}

graph_node_t *graph_find_node(graph_t *graph, const char *city_name) {
    node_t *current = graph->nodes->head;
    while (current) {
        graph_node_t *node = (graph_node_t *)current->data;
        if (strcmp(node->city_name, city_name) == 0) {
            return node;
        }
        current = current->next;
    }
    return NULL;
}

void graph_add_edge(graph_t *graph, const char *city_name1, const char *city_name2, int weight) {
    graph_node_t *node1 = graph_find_node(graph, city_name1);
    graph_node_t *node2 = graph_find_node(graph, city_name2);

    if (node1 && node2) {
        graph_edge_t *edge = (graph_edge_t *)malloc(sizeof(graph_edge_t));
        edge->weight = weight;
        edge->destination = node2;
        dll_push_back(node1->edges, edge);
    }
}

void graph_free(graph_t *graph) {
    node_t *current = graph->nodes->head;
    while (current) {
        graph_node_t *node = (graph_node_t *)current->data;
        free_dll(node->edges);
        free(node->city_name);
        free(node);
        current = current->next;
    }
    free_dll(graph->nodes);
    free(graph);

#endif // MY_GRAPH_H