#include <stdio.h>
#include "queue.h"
#include "queue.c"

int main(void) {
    int enqueue1 = 1;
    int enqueue2 = 2;
    int enqueue3 = 3;
    queue_t *queue = queue_create();
    queue_enqueue(queue, (void *)&enqueue1);
    queue_enqueue(queue, (void *)&enqueue2);
    queue_enqueue(queue, (void *)&enqueue3);
    int dequeue1 = *(int *)queue_dequeue(queue);
    int dequeue2 = *(int *)queue_dequeue(queue);
    int dequeue3 = *(int *)queue_dequeue(queue);
    queue_destroy(queue);
    printf("enqueue1: %d\n", enqueue1);
    printf("enqueue2: %d\n", enqueue2);
    printf("enqueue3: %d\n", enqueue3);
    printf("dequeue1: %d\n", dequeue1);
    printf("dequeue2: %d\n", dequeue2);
    printf("dequeue3: %d\n", dequeue3);
    return 0;
}
