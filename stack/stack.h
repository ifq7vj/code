#ifndef STACK_H
#define STACK_H

typedef struct stack_t stack_t;

struct stack_t {
    void *data;
    stack_t *next;
};

stack_t *stack_create(void);
void stack_destroy(stack_t *);
void stack_push(stack_t *, void *);
void *stack_pop(stack_t *);

#endif
