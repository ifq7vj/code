#include <stdlib.h>
#include "stack.h"

stack_t *stack_new(void) {
    stack_t *stack = malloc(sizeof(stack_t));
    return stack;
}

void stack_delete(stack_t *stack) {
    free(stack);
    return;
}

void stack_push(stack_t *stack, void *ptr) {
    stack_t *node = malloc(sizeof(stack_t));
    node->ptr = ptr;
    node->next = stack->next;
    stack->next = node;
    return;
}

void *stack_pop(stack_t *stack) {
    stack_t *node = stack->next;
    void *ptr = node->ptr;
    stack->next = node->next;
    free(node);
    return ptr;
}
