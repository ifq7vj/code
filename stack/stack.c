#include <stdlib.h>
#include "stack.h"

stack_t *stack_create(void) {
    stack_t *stack = malloc(sizeof(stack_t));
    return stack;
}

void stack_destroy(stack_t *stack) {
    free(stack);
    return;
}

void stack_push(stack_t *stack, void *data) {
    stack_t *node = malloc(sizeof(stack_t));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    return;
}

void *stack_pop(stack_t *stack) {
    stack_t *node = stack->next;
    void *data = node->data;
    stack->next = node->next;
    free(node);
    return data;
}
