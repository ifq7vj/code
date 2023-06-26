#include <stdlib.h>
#include "queue.h"

queue_t *queue_create(void) {
    queue_t *queue = malloc(sizeof(queue_t));
    node_t *node = malloc(sizeof(node_t));
    node->next = NULL;
    queue->head = node;
    queue->tail = node;
    return queue;
}

void queue_destroy(queue_t *queue) {
    free(queue->head);
    free(queue);
    return;
}

void queue_enqueue(queue_t *queue, void *data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    queue->tail->next = node;
    queue->tail = node;
    return;
}

void *queue_dequeue(queue_t *queue) {
    node_t *node = queue->head->next;
    void *data = node->data;
    queue->head->next = node->next;
    free(node);
    return data;
}
