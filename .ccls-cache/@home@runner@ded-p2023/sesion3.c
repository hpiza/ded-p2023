#include <stdio.h>

struct strVec2 {
  double x, y;
};

#define N 1000
typedef unsigned long long UInt64;
typedef struct strVec2 Vec2;

int main() {
  UInt64 entero;
  //struct strVec2 v1 = {3.0, 4.5}, v2;
  Vec2 v1 = {3.0, 4.5}, v2;
  v2.x = -1.3;
  v2.y = -2.5;
  // struct strVec2* pVec = &v1;
  Vec2* pVec = &v1;
  printf("%f, %f\n", (*pVec).x, (*pVec).y);
  printf("%f, %f\n", pVec->x, pVec->y);
  pVec->x = 6.5;
  printf("%f\n", v1.x);

  pVec = &v2;

  pVec->y -= 0.5;
  printf("%f\n", v2.y);
  printf("Tamaño de v1 en bytes: %lu\n", sizeof v1);  // Tamaño es 16: double (8) + double (8)
  printf("%p, %p\n", &v1, &v2);  // 8f00 - 8ef0 = 16 bytes
  pVec ++;
  printf("%f, %f\n", pVec->x, pVec->y);

  Vec2 vecArray[N];
  printf("Tamaño de vecArray en bytes: %lu\n", sizeof vecArray);
  printf("(%.1f, %.1f)\n", vecArray[0].x, vecArray[0].y);
  printf("(%.1f, %.1f)\n", vecArray[1].x, vecArray[1].y);
  // Algoritmo que asigna [x = 2, y = 1] a todos los vectores del arreglo, pero:
  // sin usar: vecArray y corchetes
  printf("%p, %p, %p\n", vecArray, &vecArray, &(vecArray[0]));
  Vec2* pVecArray = vecArray;
  int i;
  for(i = 0; i < N; i++, pVecArray ++) {
    pVecArray->x = 2;
    pVecArray->y = 1;    
  }  
  for(i = 0; i < 5; i ++) {
     printf("(%.1f, %.1f)\n", vecArray[i].x, vecArray[i].y);
  }  
  
  
}

int main3(void) {
  int x1 = 3, x2 = 4;
  printf("%d, %d\n", x1, x2);
  printf("%p, %p\n", &x1, &x2);
  int *pInt = &x1;
  printf("%p, %d\n", pInt, *pInt);
  pInt --;  // pInt = pInt - 1
  printf("%p, %d\n", pInt, *pInt);
  pInt += 2;
  printf("%p, %d\n", pInt, *pInt);
  printf("\n");  
  
  short int s1 = 5, s2 = 6;
  printf("%p, %p\n", &s1, &s2);
  short int* pShort = &s2;
  printf("%p, %d\n", pShort, *pShort);
  pShort ++;
  printf("%p, %d\n", pShort, *pShort);

  int intArray[100] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
  int i;
  for(i = 0; i < 6; i ++) printf("%d ", intArray[i]);
  printf("\n");
// pInt = &intArray[0];
  pInt  = intArray;  // intArray almacena la dirección de memoria del 1er elemento
  //printf("Elemento 0: %d\n", *pInt);
  //pInt ++;
  //printf("Elemento 1: %d\n", *pInt);
  for(i = 0; i < 6; i ++) {
    printf("Elemento %d: %d\n", i, *pInt);
    pInt ++;
  }
  // intArray ++; No es válido porque intArray es un apuntador constante
  
  // Imprimir todos los datos del arreglo, mientras no sean 0
  pInt = intArray;
  while(*pInt != 0) {
    printf("%d ", *pInt);
    pInt ++;
  }
  printf("\n");

  pInt -= 2;
  printf("pInt apunta a %d\n", *pInt);
  printf("pInt apunta a %d\n", pInt[0]);

  printf("El siguiente es %d\n", *(pInt + 1));
  printf("El siguiente es %d\n", pInt[1]);

  printf("El siguiente del siguiente es %d\n", *(pInt + 2));
  printf("El siguiente del siguiente es %d\n", pInt[2]);

  printf("El primer elemento del arreglo es: %d\n", *intArray);
  printf("El segundo elemento del arreglo es: %d\n", *(intArray + 1));

  for(i = 0; i < 10; i ++) {
    printf("Elemento %d: %d\n", i, *(intArray + i));  // intArray[i]
  }

  // |1, 2, 3|   --> |1, 2, 3, 4, 5, 6|
  // |4, 5, 6|  
  
  
  
  return 0;
}
