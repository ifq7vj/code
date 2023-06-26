#include <stdlib.h>
#include "stack.h"

stack_t *stack_create(void) {
    stack_t *stack = malloc(sizeof(stack_t));
    node_t *node = malloc(sizeof(node_t));
    node->next = NULL;
    stack->top = node;
    return stack;
}

void stack_destroy(stack_t *stack) {
    free(stack->top);
    free(stack);
    return;
}

void stack_push(stack_t *stack, void *data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = stack->top->next;
    stack->top->next = node;
    return;
}

void *stack_pop(stack_t *stack) {
    node_t *node = stack->top->next;
    void *data = node->data;
    stack->top->next = node->next;
    free(node);
    return data;
}
