#ifndef STACK_H_
#define STACK_H_

typedef void* Type;
typedef enum {FALSE, TRUE} Bool;
typedef struct strStack* Stack;

Stack stack_create();
void stack_push(Stack, Type);
Type stack_pop(Stack);
Bool stack_isEmpty(Stack);
int stack_size(Stack);
Type stack_top(Stack);
void stack_destroy(Stack);

#endif
