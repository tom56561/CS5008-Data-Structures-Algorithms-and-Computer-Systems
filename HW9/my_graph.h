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
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdlib.h>
#include <assert.h>
// Create a graph data structure
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* nodes;     //an array of nodes storing all of our nodes.
} graph_t;

typedef struct graph_node{
    int data;
    int visited;
    dll_t* inNeighbors;
    dll_t* outNeighbors;
} graph_node_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t* create_graph(){
    // Modify the body of this function as needed.
    graph_t* myGraph= malloc(sizeof(graph_t));
    myGraph->nodes = create_dll();
    myGraph->numEdges = 0;
    myGraph->numNodes = 0;
    return myGraph;
}

// Returns the node pointer if the node exists.
// Returns NULL if the node doesn't exist or the graph is NULL
graph_node_t* find_node( graph_t * g, int value){
    if (g == NULL)
        return NULL;

    node_t* current = g->nodes->head;
    while (current != NULL) {
        graph_node_t* node = (graph_node_t*) current->data;
        if (node->data == value)
            return node;
        current = current->next;
    }
    return NULL;
}

// Creates a graph node
// Note: This relies on your dll implementation.
graph_node_t * create_graph_node(int value){
    graph_node_t * graph_node = malloc(sizeof(graph_node_t));
    
    if ( graph_node == NULL ) return NULL;
    
    graph_node->data = value;
     graph_node->visited = 0;
    graph_node->inNeighbors = create_dll();
    graph_node->outNeighbors = create_dll();
    
    return graph_node;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node already exists )
// Returns -1 if the graph is NULL.
int graph_add_node(graph_t* g, int value){
    if ( g == NULL ) return -1;
    
    if (find_node(g, value) != NULL) return 0;
    
    graph_node_t * newNode = create_graph_node(value);
    if ( newNode == NULL ) return -1;
    
    assert(g->nodes);
    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    
    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node doesn't exist )
// Returns -1 if the graph is NULL.
int graph_remove_node(graph_t* g, int value){
    if (g == NULL) return -1;

    // Find the node with the given value
    node_t* current = g->nodes->head;
    while (current != NULL) {
        graph_node_t* node = (graph_node_t*) current->data;
        if (node->data == value) {
            // Remove this node from all in neighbors' lists
            node_t* inCurrent = node->inNeighbors->head;
            while (inCurrent != NULL) {
                graph_node_t* inNode = (graph_node_t*) inCurrent->data;
                dll_remove(inNode->outNeighbors, dll_get_index(inNode->outNeighbors, node));
                inCurrent = inCurrent->next;
            }

            // Remove this node from all out neighbors' lists
            node_t* outCurrent = node->outNeighbors->head;
            while (outCurrent != NULL) {
                graph_node_t* outNode = (graph_node_t*) outCurrent->data;
                dll_remove(outNode->inNeighbors, dll_get_index(outNode->inNeighbors, node));
                outCurrent = outCurrent->next;
            }

            // Remove the node from the graph's node list
            dll_remove(g->nodes, dll_get_index(g->nodes, node));
            g->numNodes--;

            // Free the memory allocated for the node
            free(node->inNeighbors);
            free(node->outNeighbors);
            free(node);

            return 1;
        }

        current = current->next;
    }

    return 0;
        
   
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
// Returns -1 if the graph is NULL.
int graph_add_edge(graph_t * g, int source, int destination){
    if (g == NULL) return -1;

    // Check if the source and destination nodes exist in the graph
    if (source < 0 || source >= g->numNodes || destination < 0 || destination >= g->numNodes) return 0;

    // Check if the edge already exists
    dll_t* outNeighbors = ((graph_node_t*)(dll_get(g->nodes, source)))->outNeighbors;
    if (dll_get(outNeighbors, destination) != NULL) return 0;

    // Add destination to the out neighbors of source
    if (dll_push_back(outNeighbors, &(g->nodes[destination])) == 0) return 0;

    // Add source to the in neighbors of destination
    dll_t* inNeighbors = ((graph_node_t*)(dll_get(g->nodes, destination)))->inNeighbors;
    if (dll_push_back(inNeighbors, &(g->nodes[source])) == 0) {
        // If adding to the in neighbors failed, remove the added out neighbor from source
        dll_remove(outNeighbors, dll_size(outNeighbors) - 1);
        return 0;
    }

    // Increment the number of edges in the graph
    g->numEdges++;

    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
// Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t * g, int source, int destination){
    if (g == NULL) return -1;

    graph_node_t* src_node = find_node(g, source);
    graph_node_t* dest_node = find_node(g, destination);

    if (src_node == NULL || dest_node == NULL) return 0;
    if (dll_get_index(src_node->outNeighbors, dest_node) == -1) return 0;

    dll_remove(src_node->outNeighbors, dll_get_index(src_node->outNeighbors, dest_node));
    dll_remove(dest_node->inNeighbors, dll_get_index(dest_node->inNeighbors, src_node));

    g->numEdges--;

    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist )
// Returns -1 if the graph is NULL.
int contains_edge( graph_t * g, int source, int destintaion){
    if (g == NULL) return -1;

    graph_node_t* src_node = find_node(g, source);
    graph_node_t* dest_node = find_node(g, destintaion);

    if (src_node == NULL || dest_node == NULL) return 0;

    return (dll_get_index(src_node->outNeighbors, dest_node) != -1) ? 1 : 0;
}

// Returns dll_t* of all the in neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getInNeighbors( graph_t * g, int value ){
    if (g == NULL) return NULL;

    graph_node_t* target = find_node(g, value);
    if (target == NULL) return NULL;

    return target->inNeighbors;
}

// Returns the number of in neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors( graph_t * g, int value){
    if (g == NULL) return -1;

    graph_node_t* target = find_node(g, value);
    if (target == NULL) return -1;

    return dll_size(target->inNeighbors);
}

// Returns dll_t* of all the out neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getOutNeighbors( graph_t * g, int value ){
    if (g == NULL) return NULL;

    graph_node_t* target = find_node(g, value);
    if (target == NULL) return NULL;

    return target->outNeighbors;
}

// Returns the number of out neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors( graph_t * g, int value){
    if (g == NULL) return -1;

    graph_node_t* target = find_node(g, value);
    if (target == NULL) return -1;

    return dll_size(target->outNeighbors);
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t* g){
    if (g == NULL) return -1;

    return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t* g){
    if (g == NULL) return -1;

    return g->numEdges;
}

// Helper function to reset visited flags of all nodes to 0
void reset_visited(graph_t *g) {
    node_t* current = g->nodes->head;
    while (current != NULL) {
        graph_node_t* node = (graph_node_t*) current->data;
        node->visited = 0;
        current = current->next;
    }
}

// Helper function for DFS traversal
int dfs(graph_node_t* node, int dest) {
    if (node->data == dest) {
        return 1;
    }

    node->visited = 1;
    node_t* current = node->outNeighbors->head;
    while (current != NULL) {
        graph_node_t* outNode = (graph_node_t*) current->data;
        if (!outNode->visited) {
            if (dfs(outNode, dest)) {
                return 1;
            }
        }
        current = current->next;
    }

    return 0;
}

// Helper function for detecting cycles using DFS
int dfs_cycle(graph_node_t* node) {
    node->visited = 1;
    node_t* current = node->outNeighbors->head;
    while (current != NULL) {
        graph_node_t* outNode = (graph_node_t*) current->data;
        if (!outNode->visited) {
            if (dfs_cycle(outNode)) {
                return 1;
            }
        } else {
            return 1;
        }
        current = current->next;
    }

    node->visited = 0;
    return 0;
}

// returns 1 if we can reach the destination from source
// returns 0 if it is not reachable
// returns -1 if the graph is NULL (using BFS)
int graph_is_reachable(graph_t * g, int source, int dest){
    if (g == NULL) return -1;

    graph_node_t* src_node = find_node(g, source);
    if (src_node == NULL) return 0;

    reset_visited_flags(g);
    return dfs(src_node, dest);
}


// returns 1 if there is a cycle in the graph
// returns 0 if no cycles exist in the graph
// returns -1 if the graph is NULL 
// You may use either BFS or DFS to complete this task.
int graph_has_cycle(graph_t * g){
    if (g == NULL) return -1;

    reset_visited_flags(g);
    node_t* current = g->nodes->head;
    while (current != NULL) {
        graph_node_t* node = (graph_node_t*) current->data;
        if (!node->visited) {
            if (dfs_cycle(node)) {
                return 1;
            }
        }
        current = current->next;
    }

    return 0;
}


// Helper function for DFS traversal to print path
int dfs_print_path(graph_node_t* node, int dest) {
    if (node->data == dest) {
        printf("%d", node->data);
        return 1;
    }

    node->visited = 1;
    node_t* current = node->outNeighbors->head;
    while (current != NULL) {
        graph_node_t* outNode = (graph_node_t*) current->data;
        if (!outNode->visited) {
            if (dfs_print_path(outNode, dest)) {
                printf(" <- %d", node->data);
                return 1;
            }
        }
        current = current->next;
    }

    return 0;
}


// prints any path from source to destination if there 
// exists a path from the source to the destination.
// Note: Consider using one of the other functions to help you
//       determine if a path exists first
// (Choose either BFS or DFS, typically DFS is much simpler)
//
// Returns 1 if there is a path from source to destination
// Returns 0 if there is not a path from a source to destination
// Returns -1 if the graph is NULL
int graph_print_path(graph_t * g, int source, int dest){
    if (g == NULL) return -1;

    graph_node_t* src_node = find_node(g, source);
    if (src_node == NULL) return 0;

    reset_visited(g);
    if (dfs_print_path(src_node, dest)) {
        printf("\n");
        return 1;
    }
    
    return 0;
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the program terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t* g){
    // Make sure g is not NULL
    if (g == NULL) return;
    int i;
    // Free all the in and out neighbor DLLs of each graph node
    for (i = 0; i < g->numNodes; i++) {
        graph_node_t* node = (graph_node_t*)(dll_get(g->nodes, i));
        if (node->inNeighbors != NULL) free_dll(node->inNeighbors);
        if (node->outNeighbors != NULL) free_dll(node->outNeighbors);
    }

    // Free the DLL of nodes and the graph itself
    if (g->nodes != NULL) free_dll(g->nodes);
    free(g);
}

#endif
