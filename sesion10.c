#include <stdio.h>
#include <stdlib.h>

int globalCalls = 0;

void function(int n) {
  static int calls = 0;
  int x = 10;
  calls ++;
  globalCalls ++;
  printf("%p, %p, %p\n", &calls, &x, &globalCalls);
  printf("Calls: %d. Global calls: %d\n", calls, globalCalls);
  if(n > 0) function(n - 1);
}

int main10a() {
  function(1);
  function(1);
  globalCalls ++;
  //calls ++;
  printf("%d\n", globalCalls);
  printf("%p, %p\n", function, main10a);

  int arreglo[5] = {10};
  printf("%p, %p, %p\n", &arreglo[0], &arreglo, arreglo);
  // ------------------ Memoria dinámica --------------------- 
  // Funciones para reservar memoria: malloc, calloc, realloc, viven en: <stdlib.h>
  // Sintaxis para malloc: void* ptr = malloc(size_in_bytes)
  malloc(20);        // se reservan 20 bytes, ¿pero para qué?
  malloc(5 * 4);     // se reserva espacio para 5 números enteros, 
                     // ¿seguro que un int ocupa 4 bytes?
  malloc(5 * sizeof(int));  // se reserva espacio para 5 valores int, 
                            // el tamaño en bytes que sea necesario
  // Se reservó el espacio, pero ¿dónde está? 
  // malloc entrega la dirección de memoria del primer espacio
  void* ptr = malloc(5 * sizeof(int));
  // ya tengo la dirección de inicio, pero yo quería números enteros
  // *ptr = 5;  // No puedo hacer nada interesante con ptr por ser void*
  printf("%p\n", ptr);
  // es responsabilidad del programar, interpretar el área de memoria reservada
  // voy a interpretar la dirección de inicio del bloque, como la dirección
  // de inicio de un arreglo de enteros
  int* array = (int*) malloc(5 * sizeof(int));
  array[0] = 10; array[1] = 25;
  *(array + 2) = 30;  *(array + 3) = 45;  
  printf("%p, %p, %p\n", &array[0], &array, array);
  int i;
  for(i = 0; i < 5; i ++) printf("%d, ", array[i]);
  printf("\n");

  // Separar la declaración de la reserva de memoria
  float* farray = NULL;
  // obtenemos el tamaño del arreglo (lo leemos de un archivo)
  // const int N = 10;
  int N;
  printf("Tamaño del arreglo: ");
  scanf("%d", &N);
  farray = (float*) malloc(N * sizeof(float));
  farray[0] = 3.4;
  farray[N - 1] = 4.5;
  
  return 0;
}

//-----------------Constantes y apuntadores-------------------------------------------
int main10() {
  // Constantes y apuntadores
  const int edad1 = 25;
  // edad = 6;  Error de sintaxis porque edad es const
  int edad2 = 18;
  int edad3 = 15;
  int const edad4 = 35;
  
  int *ptr1 = &edad2;
  printf("%p\n", ptr1);
  *ptr1 = 19;            // Modificar valor apuntado
  printf("%d\n", edad2);
  ptr1 = &edad3;         // Modificar a dónde apunto
  printf("%p\n", ptr1);
  // ptr1 = &edad1;      // Warning: apuntando a una constante

  const int *ptr2 = &edad1;    // POINTER TO CONSTANT
  // int const *ptr2 = &edad1;  // Otra manera
  printf("%p\n", ptr2);
  // *ptr2 = 26;    // Error de sintaxis: ptr2 es Pointer to constant
  ptr2 = &edad4;
  printf("%p\n", ptr2);
  ptr2 = &edad2;    // Puedo apuntar a una No constante (variable)
  // *ptr2 = 15;    // Sin embargo, no puedo modificar su valor

  int* const ptr3 = &edad2;    // CONSTANT POINTER
  *ptr3 = 25;
  printf("%d\n", edad2);
  // ptr3 = &edad3;        // Error: no puedo apuntar a otro lado
  // ptr3 ++;              // Error: no puedo apuntar a otro lado

  const int* const ptr4 = &edad1;   // CONSTANT POINTER TO CONSTANT
  // *ptr4 = 25;     Error: es Pointer to constant
  // ptr4 = &edad4;  Error es: Constant Poiner
  printf("%p, %d\n", ptr4, *ptr4);
  
  return 0;
}
