#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 3
// 1. Crea una estructura capaz de almacenar el precio, las existencias y el
// nombre (hasta 30 caracteres) de un producto. OK
// 2. Solicita al usuario cuántos productos dará de alta. OK
// 3. Crea un arreglo con memoria dinámica para almacenar dichos productos.
// 4. Solicita los datos de todos los productos.
// 5. Al final, imprime todos los productos de forma tabular y libera memoria
//    Nombre      Precio   Existencias
// 1. Playera     250      30
// 2. Gorra       380      50
// 3. Sudadera    530      20
/// ...


//1.
typedef struct {
  int precio;
  int existencias;
  char nombre[30];
} Producto;
//3. 

Producto* readData(int N) {
  Producto* productos = (Producto*) malloc(N * sizeof(Producto));
  for(int i=0; i<N; i++) {
    printf("\nProduct %d\nExistencias: ", i+1);
    scanf("%d", &productos[i].existencias);
    printf("Precio: ");
    scanf("%d", &productos[i].precio);
    printf("Nombre: ");
    scanf("%s", productos[i].nombre);
  }
  return productos;
}

// *productos->[0] Producto(esto ya tiene las especificaciones en struct)
//             [2] Producto(esto ya tiene las especificaciones en struct)
//             [...]
//             [n] Producto(esto ya tiene las especificaciones en struct)

void printData(Producto* productos, int N) {
  printf(" #    Nombre    Precio    Cantidad\n");
  for(int i=0; i<N; i++){
    printf("%4d %10s %6d %4d\n", i+1, productos[i].nombre,  productos[i].precio ,productos[i].existencias);
  }
}

// Arreglo dinámico de estructuras
int main13() {
  //2.
  int cantidad;
  printf("Escribe cuantos productos deseas registrar: ");
  scanf("%d",&cantidad);
  Producto* productos = readData(cantidad);
  printData(productos, cantidad);
  free(productos);
  return 0;
}


Producto** readData1(int N) {
  Producto** productos = (Producto**) malloc(N * sizeof(Producto*));
  for(int i=0; i<N; i++) {
    productos[i] = (Producto*) malloc(sizeof(Producto));
    printf("\nProduct %d\nExistencias: ", i+1);
    scanf("%d", &productos[i]->existencias);
    printf("Precio: ");
    scanf("%d", &productos[i]->precio);
    printf("Nombre: ");
    scanf("%s", productos[i]->nombre);
  }
  return productos;
}

void printData1(Producto** productos, int N) {
  printf("  #     Nombre   Precio   Cantidad\n");
  for(int i=0; i<N; i++){
    printf("%4d %10s %6d %4d\n", i+1, productos[i]->nombre,  productos[i]->precio, productos[i]->existencias);
  }
}

void freeData1(Producto** productos, int N) {
  for(int i=0; i<N; i++) {
    free(productos[i]);
  }
  free(productos);
}

void swap13(int* a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void initArray(int** array, int N, int v) {
  *array = (int*) malloc(N * sizeof(int));
  for(int i = 0; i < N; i ++) (*array)[i] = v;
  //printf("initArray: %p, %d\n", *array, (*array)[0]);
}

// Arreglo dinámico de apuntadores a estructuras
int main1313() {
  int x = 5, y = 6;
  swap13(&x, &y);
  printf("%d, %d\n", x, y);
  int* array1 = NULL;
  initArray(&array1, 10, 3);
  printf("main: %p, %d\n", array1, array1[0]);
  
  /*
  int cantidad;
  printf("Escribe cuantos productos deseas registrar: ");
  scanf("%d",&cantidad);
  Producto** productos = readData1(cantidad);
  printData1(productos, cantidad);
  freeData1(productos, cantidad);
  return 0;*/
}