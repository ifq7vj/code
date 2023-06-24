#include <stdio.h>
#include "stack.h"

int main(void) {
    stack_t *stack = stack_new();
    int push1 = 42;
    int push2 = 123;
    stack_push(stack, (void *)&push1);
    stack_push(stack, (void *)&push2);
    int pop1 = *(int *)stack_pop(stack);
    int pop2 = *(int *)stack_pop(stack);
    stack_delete(stack);
    printf("push1: %d\n", push1);
    printf("push2: %d\n", push2);
    printf("pop1: %d\n", pop1);
    printf("pop2: %d\n", pop2);
    return 0;
}
