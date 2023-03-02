#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

// límite para memoria estática
#define M 300000  
// límite para memoria dinámica
#define N 30000000  

typedef struct {
	double x, y, z;
} Vec3;  // Mide 12 bytes

int* sum(int* a1, int* a2, int n) {
  int* a3 = (int*) malloc(n * sizeof(int));
  //int a3[n];
  int i;
  for(i = 0; i < n; i ++) a3[i] = a1[i] + a2[i];
  printf("a3=%p\n", &a3[0]);
  return a3;
}

int main11() {
  int a1[] = { 1, 2, 3, 4 };
  int a2[] = { 5, 6, 7, 8 };
  int* a3 = sum(a1, a2, 4);
  printf("%d, %d, %d, %d\n", a3[0], a3[1], a3[2], a3[3]);

  int a4[] = { 3, 4, 5, 6 };
  int a5[] = { 5, 6, 7, 8 };
  int* a6 = sum(a4, a5, 4);
  printf("%d, %d, %d, %d\n", a6[0], a6[1], a6[2], a6[3]);
  printf("%d, %d, %d, %d\n", a3[0], a3[1], a3[2], a3[3]);
  
  struct rlimit limit;

  getrlimit (RLIMIT_STACK, &limit);
  printf ("\nStack Limit = %ld and %llu max\n", limit.rlim_cur, limit.rlim_max);
	Vec3 starray[M];
  unsigned long long i;
  for(i = 0; i < M; i ++) {
    starray[i].x = 1;
    starray[i].y = 2;
    starray[i].z = 3;
  } 
	printf("Memoria estática: %.1f\n", starray[M-1].x);
	printf("Tamaño del arreglo: %llu\n", sizeof(starray));

	Vec3* dyarray = malloc(N * sizeof(Vec3));
  for(i = 0; i < N; i ++) {
    dyarray[i].x = 1;
    dyarray[i].y = 2;
    dyarray[i].z = 3;
  }
	printf("Memoria dinámica: %.1f\n", dyarray[N-1].x);
	printf("Tamaño del arreglo: %llu\n", sizeof(dyarray));

    /*
  int* ptr = NULL;
  int i;
  for(i = 0; i < 10; i ++) {
    //ptr = (int*) malloc(64 * sizeof(int));
    ptr = (int*) calloc(64, sizeof(int));
    printf("%d\n", ptr[10]);
    ptr[10] = 5000;
    printf("%p, %p, %d\n", &ptr, ptr, ptr[10]);
    ptr ++;
    free(ptr);
    printf("%d\n\n", ptr[10]);
  } */
  return 0;
}
