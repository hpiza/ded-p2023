#include "Stack.h"
#include <stdlib.h>

struct strNode {
  Type data;
  struct strNode *prior;
};
typedef struct strNode *Node;

struct strStack {
  Node top;
  int size;
};

Bool stack_isEmpty(Stack s) {
  // se puede saber con el valor de top (nulo) o con el de size (0)
  // return s->top == NULL;
  return s->size == 0;
}

Stack stack_create() {
  // Hay que implementar este método:
  // crear un Stack en memoria dinámica y asignar valores default a top, size
  Stack stack = (Stack) malloc(sizeof(struct strStack));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

void stack_push(Stack s, Type data) {
  // Paso 1) crear un nuevo nodo n que almacene el dato a guardar data
  Node n = (Node) malloc(sizeof(struct strNode));
  n->data = data;
  // Paso 2) el anterior a n será el que actualmente es el tope
  n->prior = s->top;
  // Paso 3) el nuevo tope será n
  s->top = n;
  // Paso 4) incrementar el tamaño de la pila
  s->size++;
}

Type stack_pop(Stack s) {
  if(stack_isEmpty(s)) return NULL;
  Node n = s->top;
  Type d = n->data;
  s->top = n->prior;
  free(n);
  s->size--;
  //saca dato del primer nodo TOP
  return d;
}

int stack_size(Stack s) {
  // se devuelve el valor de size
  return s->size;
}

Type stack_top(Stack s) {
  // se devuelve el contenido del top o nulo si la pila está vacía
  if (s->top == NULL) {
    return NULL;
  } else {
    //Si el tope no es nulo, devolver el dato que almacena el tope
    return s->top->data;
  }
}

void stack_destroy(Stack s) {
  while(!stack_isEmpty(s)) stack_pop(s);
  free(s);
}
