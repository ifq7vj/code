#include <stdio.h>
#include "stack.h"
#include "stack.c"

int main(void) {
    int push1 = 1;
    int push2 = 2;
    int push3 = 3;
    stack_t *stack = stack_create();
    stack_push(stack, (void *)&push1);
    stack_push(stack, (void *)&push2);
    stack_push(stack, (void *)&push3);
    int pop1 = *(int *)stack_pop(stack);
    int pop2 = *(int *)stack_pop(stack);
    int pop3 = *(int *)stack_pop(stack);
    stack_destroy(stack);
    printf("push1: %d\n", push1);
    printf("push2: %d\n", push2);
    printf("push3: %d\n", push3);
    printf("pop1: %d\n", pop1);
    printf("pop2: %d\n", pop2);
    printf("pop3: %d\n", pop3);
    return 0;
}
