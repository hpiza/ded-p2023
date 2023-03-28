#include "Queue.h"
#include <stdio.h>

int main18() {
  Queue q, z;
  
  q = queue_create();
  printf("Queue size: %d\n", queue_size(q));
  printf("Queue empty: %d\n", queue_isEmpty(q));
  printf("------Queue q------\n");
  char a[] = "Hola", b[] = "Como", c[] = "Estas";
  queue_offer(q, &a);
  queue_offer(q, &b);
  queue_offer(q, &c);
  printf("Queue size: %d\n", queue_size(q));
  printf("Queue empty: %d\n", queue_isEmpty(q));

  printf("Primer palabra: %s\n", (char*) queue_peek(q));
  printf("Se saca palabra: %s\n", (char*) queue_poll(q));
  printf("Nuevo First queue: %s\n", (char*) queue_peek(q));

  while(!queue_isEmpty(q)){
    printf("Word: %s\n", (char*) queue_poll(q));
  }
  printf("Queue empty: %d\n", queue_isEmpty(q));//el 1 en bool es TRUE
  
  queue_destroy(q);

  printf("------------------\n\n");
  printf("------Queue z------\n");
  int d=1, e=2, f=3, g=4, h=5, i=6;
  z = queue_create();
  printf("Queue size: %d\n", queue_size(z));
  printf("Queue empty: %d\n", queue_isEmpty(z));
  queue_offer(z, &d);
  queue_offer(z, &e);
  queue_offer(z, &f);
  queue_offer(z, &g);
  queue_offer(z, &h);
  queue_offer(z, &i);
  printf("Queue size: %d\n", queue_size(z));
  printf("Queue empty: %d\n", queue_isEmpty(z));

  int *tmp = (int*) queue_peek(z);
  printf("first element with peek: %d\n", *tmp);
  
  tmp = (int*) queue_poll(z);
  printf("first element with poll: %d\n", *tmp);
  tmp = (int*) queue_peek(z);
  printf("new first element after poll with peek: %d\n", *tmp);
  
  while(!queue_isEmpty(z)){
    tmp = (int*) queue_poll(z);
    printf("Number: %d\n", *tmp);
  }

  printf("Queue empty: %d\n", queue_isEmpty(z));//el 1 en bool es TRUE
  
  queue_destroy(z);
  
  return 0;
}
