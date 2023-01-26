#include <stdio.h>

struct strVec2 {
  double x, y;
};
typedef struct strVec2 Vec2;

void duplicarV(Vec2* pv) {
  //(*pv).x *= 2;
  //(*pv).y *= 2;
  pv->x *= 2;
  pv->y *= 2;
  printf("(%.1f, %.1f), %p, %p\n", pv->x, pv->y, pv, &pv);  
}

void duplicar(int* x) {
  // (*x) = (*x) * 2;
  *x *= 2;
  // printf("x en duplicar: %d, %p\n", x, &x);
}

void print1(int array[], int N) {
//void print1(int* array, int N) {
  printf("Array en print1: %p, %p, %p\n", &array, array, &array[0]);
  int i;
  array[0] = 5;  
  // *array = 5;    // array[0] = 5
  // array[5] = 6;  // *(array + 1) = 6
  for(i = 0; i < N; i ++) printf("%d ", array[i]);
  printf("\n");
}

int main() {
  int array[20] = {1, 2, 3, 4};
  printf("Array en main:   %p, %p, %p\n", &array, array, &array[0]);
  print1(array, 10);
  printf("%d, %d\n", array[0], array[1]);
  
  Vec2 v = {1, 3};
  duplicarV(&v);
  printf("(%.1f, %.1f), %p\n", v.x, v.y, &v);  
  
  int x = 30;
  scanf("%d", &x);
  duplicar(&x);
  printf("x en main: %d, %p\n", x, &x);  // x almacena el doble

  print1(&x, 3);
  printf("x = %d\n", x);

  float farray[] = {1.2, 2.4, 3.6};
  // farray ++;
  float* pf = farray;  // farray = &farray = &farray[0]
  *pf = 4.8;  // pf[0] = 4.8;
  pf += 2;
  pf[0] = 7.2;

  for(int i = 0; i < 3; i ++) printf("%.1f ", farray[i]);
  printf("\n");
  
  float* pf1 = farray;
  int d = pf - pf1;  // diferencia de apuntadores
  // pf1 está en la posición 0
  // pf  está en la posición 2
  // d = 2 - 0 = 2
  printf("%d, %d\n", d, d * (int) sizeof(float));  
  
  return 0;
}
