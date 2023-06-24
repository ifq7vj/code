#ifndef STACK_H
#define STACK_H

typedef struct stack_t stack_t;

struct stack_t {
    void *ptr;
    stack_t *next;
};

stack_t *stack_new(void);
void stack_delete(stack_t *stack);
void stack_push(stack_t *stack, void *ptr);
void *stack_pop(stack_t *stack);

#endif
