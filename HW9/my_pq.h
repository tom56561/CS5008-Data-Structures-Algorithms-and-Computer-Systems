#ifndef MY_PQ_H
#define MY_PQ_H

#include "my_graph.h"
#include "my_dll.h"
#include <limits.h>

typedef struct pq {
    dll_t *list;
} pq_t;

pq_t *pq_create() {
    pq_t *queue = (pq_t *)malloc(sizeof(pq_t));
    queue->list = create_dll();
    return queue;
}

void pq_enqueue(pq_t *queue, graph_node_t *node) {
    dll_push_back(queue->list, node);
}

graph_node_t *pq_dequeue_min(pq_t *queue) {
    node_t *current = queue->list->head;
    node_t *min_node = NULL;
    int min_cost = INT_MAX;

    while (current) {
        graph_node_t *node = (graph_node_t *)current->data;
        if (node->cost < min_cost) {
            min_cost = node->cost;
            min_node = current;
        }
        current = current->next;
    }

    if (min_node) {
        graph_node_t *min_data = (graph_node_t *)min_node->data;
        if (queue->list->head == min_node) {
            dll_pop_front(queue->list);
        } else if (queue->list->tail == min_node) {
            dll_pop_back(queue->list);
        } else {
            min_node->previous->next = min_node->next;
            min_node->next->previous = min_node->previous;
            queue->list->count--;
            free(min_node);
        }
        return min_data;
    }

    return NULL;
}

int pq_is_empty(pq_t *queue) {
    return dll_size(queue->list) == 0;
}

void pq_free(pq_t *queue) {
    free_dll(queue->list);
    free(queue);
}

#endif // MY_PQ_H