#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

struct strNode {
  Type data;
  struct strNode* next;
};
typedef struct strNode *Node;

struct strQueue {
  struct strNode *first, *last;
  int size;
};


Queue queue_create() {
  Queue q = (Queue) malloc(sizeof(struct strQueue));
  q->first=NULL;
  q->last=NULL;
  q->size=0;
  return q;
}

int queue_size(Queue q) {
  return q->size;
}

Bool queue_isEmpty(Queue q) {
  return q->size==0;// && q->first == NULL && q->last == NULL;
}

void queue_offer(Queue q, Type data) {
  Node node = (Node) malloc(sizeof(struct strNode));
  node->data = data;
  //(1|next)->(2|next)->(last|next)->NULL;
  node->next = NULL;
  if(queue_isEmpty(q)) q->first = node;
  else q->last->next = node;
  q->last = node;
  q->size++;  
}

Type queue_poll(Queue q) {
  if (queue_isEmpty(q)) return NULL;
  Node node = q->first;
  Type data = node->data;
  q->first = node->next;
  free(node);
  q->size--;
  return data;
}

Type queue_peek(Queue q) {
  if (queue_isEmpty(q)) return NULL;
  //ensenia primer dato en la fila
  return q->first->data;
}

void queue_destroy(Queue q) {
  int node_count = queue_size(q);
  //paso para destruir cascaron o espacio de memoria 
  while(!queue_isEmpty(q)) queue_poll(q);
  
  /*
  for (int i =0; i< node_count; i++)
    {
      Node* temp = q -> first;
      q -> first = q -> first -> next;
      free(temp);
    }
  *///esto se podria borrar
  free(q);
  
}
