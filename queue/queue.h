#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_t queue_t;
typedef struct node_t node_t;

struct queue_t {
    node_t *head;
    node_t *tail;
};

struct node_t {
    void *data;
    node_t *next;
};

queue_t *queue_create(void);
void queue_destroy(queue_t *queue);
void queue_enqueue(queue_t *queue, void *data);
void *queue_dequeue(queue_t *queue);

#endif
