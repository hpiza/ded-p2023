#include "Stack.h"
#include <stdio.h>

int main() { 
  Stack st1, st2, st3;
  
  st1 = stack_create();
  float a = 5, b = 6, c = 7.5, d = 10.3, e = 3.1416;  
  stack_push(st1, &a);
  stack_push(st1, &b);
  stack_push(st1, &c);
  stack_push(st1, &d);
  stack_push(st1, &e);
  printf("Size: %d\n", stack_size(st1));
  if(stack_isEmpty(st1)) printf("Pila vacía\n");
  else printf("Pila no vacía\n");
  float* top = (float*) stack_top(st1);
  printf("Tope: %f\n", *top);

  while(!stack_isEmpty(st1)) {
    float* p = (float*) stack_pop(st1);
    printf("%f\n", *p);
  }    
  stack_destroy(st1);
  
  st2 = stack_create();
  char str1[] = "hola";
  char str2[] = "adiós";
  char str3[] = "bye";
  stack_push(st2, str1);
  stack_push(st2, str2);
  stack_push(st2, str3);
  while(!stack_isEmpty(st2)) {
    char* s = (char*) stack_pop(st2);
    printf("%s\n", s);
  }  
  stack_destroy(st2);
  
  return 0;
}
