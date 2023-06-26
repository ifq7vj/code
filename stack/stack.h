#ifndef STACK_H
#define STACK_H

typedef struct stack_t stack_t;
typedef struct node_t node_t;

struct stack_t {
    node_t *top;
};

struct node_t {
    void *data;
    node_t *next;
};

stack_t *stack_create(void);
void stack_destroy(stack_t *);
void stack_push(stack_t *, void *);
void *stack_pop(stack_t *);

#endif
