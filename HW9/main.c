// Name: Po-Shen Lee
// Date: Apr 21
// Traveling Map HW9

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_dll.h"
#include "my_graph.h"
#include "my_pq.h"


int edge_weight(graph_node_t *u, graph_node_t *v) {
    node_t *current = u->edges->head;
    while (current) {
        graph_edge_t *edge = (graph_edge_t *)current->data;
        if (edge->destination == v) {
            return edge->weight;
        }
        current = current->next;
    }
    return INT_MAX;
}

void calculate_shortest(graph_t *graph, const char *source_city_name) {
    pq_t *queue = pq_create();
    node_t *current = graph->nodes->head;

    while (current) {
        graph_node_t *u = (graph_node_t *)current->data;
        u->cost = INT_MAX;
        u->from = NULL;
        pq_enqueue(queue, u);
        current = current->next;
    }

    graph_node_t *source_node = graph_find_node(graph, source_city_name);
    source_node->cost = 0;

    while (!pq_is_empty(queue)) {
        graph_node_t *u = pq_dequeue_min(queue);
        node_t *edge_current = u->edges->head;
        while (edge_current) {
            graph_edge_t *edge = (graph_edge_t *)edge_current->data;
            graph_node_t *v = edge->destination;
            int alt = u->cost + edge_weight(u, v);
            if (alt < v->cost) {
                v->cost = alt;
                v->from = u;
            }
            edge_current = edge_current->next;
        }
    }

    pq_free(queue);
}

typedef struct City {
    const char *name;
    int index;
} City;

int main() {


	//List of cities
	struct City cities[] = {
		{"Lisbon", 1},
		{"Madrid", 2},
		{"Naples", 3},
		{"Rome", 4},
		{"Hamburg", 5},
		{"Copenhagen", 6},
		{"Berlin", 7},
		{"Warsaw", 8},
		{"Amsterdam", 9},
		{"Brussels", 10},
		{"Prague", 11},
		{"Vienna", 12},
		{"Budapest", 13},
		{"Belgrade", 14},
		{"Trieste", 15},
		{"Munich", 16},
		{"Genoa", 17},
		{"Paris", 18},
		{"Bern", 19}
	};

	// Read data from datafile city.dat
    FILE *file = fopen("city.dat", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

	

    // Create a graph and read the data from the file
    graph_t *graph = graph_create();
    for (int i = 0; i < sizeof(cities) / sizeof(cities[0]); i++) {
        graph_add_node(graph, cities[i].name);
    }

    char city_name1[20], city_name2[20];
    int weight;
    while (fscanf(file, "%19s %19s %d", city_name1, city_name2, &weight) == 3) {
        graph_add_edge(graph, city_name1, city_name2, weight);
        graph_add_edge(graph, city_name2, city_name1, weight);
    }

    fclose(file);

    while (true) {
        // Display the list of cities
        printf("Please select an origin city\n");
        printf("Enter a number associated with one of the cities below:\n");
        for (int i = 0; i < sizeof(cities) / sizeof(cities[0]); i++) {
            printf("%-15s --- %2d\n", cities[i].name, i + 1);
        }
        printf("TO QUIT ENTER --  0\n");
        printf("$> ");

        // Get input for the origin city
        int origin_index, destination_index;
        scanf("%d", &origin_index);
        if (origin_index == 0) {
            break;
        }

        printf("Please select a destination city\n");
        printf("Enter a number associated with one of the cities below:\n");
        for (int i = 0; i < sizeof(cities) / sizeof(cities[0]); i++) {
            if (i + 1 != origin_index) {
                printf("%-15s --- %2d\n", cities[i].name, i + 1);
            }
        }
        printf("$> ");

        // Get input for the destination city
        scanf("%d", &destination_index);

        // Calculate the shortest path
        calculate_shortest(graph, cities[origin_index - 1].name);
        graph_node_t *destination_node = graph_find_node(graph, cities[destination_index - 1].name);

        // Print the result
        printf("ORIGIN:      %s\n", cities[origin_index - 1].name);
        printf("DESTINATION: %s\n", cities[destination_index - 1].name);
        printf("LENGTH:      %d\n", destination_node->cost);

        printf("PATH CITIES:");
        graph_node_t *current_node = destination_node;
        while (current_node) {
            printf(" %s", current_node->city_name);
            current_node = current_node->from;
        }
        printf("\n\n");
    }

    // Free the graph
    graph_free(graph);

    return EXIT_SUCCESS;


    return EXIT_SUCCESS;
}
