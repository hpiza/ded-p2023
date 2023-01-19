#include <stdio.h>

int main() {
  char c = 'A', d = 'B';
  int edad = 23;
  long long millis = 15314738293;
  printf("%p\n", &c);
  printf("%d", &d);
  printf("%p\n", &edad);
  printf("%p\n", &millis);

  int ptrEdad = &edad;
  printf("%p\n", ptrEdad);
  char *ptrD = &d;
  printf("%p\n", ptrD);
  
  printf("%p\n", &ptrEdad);
  printf("%p\n", &ptrEdad);
  ptrD = &c;
  printf("%p\n", ptrD);

  long long *ptrL1 = 0, *ptrL2 = NULL;
  printf("%p,%p\n", ptrL1, ptrL2);


  return 0;
}

// UwU
//nwn
//OwO
//:v