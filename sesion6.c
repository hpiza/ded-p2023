#include <stdio.h>

//--------------------------------- Parte 2 -----------------------------------
void saludar() { printf("Hola\n"); }

void despedirse() { printf("Adiós\n"); }

void imprimirDoble(int x) { printf("%d\n", 2 * x); }

void imprimirTriple(int a) { printf("%d\n", 3 * a); }

int sumar(int a, int b) { return a + b; }

int restar(int x, int y) { return x - y; }

int mainSeis() {
  void (*serEducado)(void) = NULL;
  serEducado = saludar;
  // seAmable!=serEducado,Jajaja
  serEducado();
  serEducado = despedirse;
  serEducado();
  printf("%p, %p, %p\n", saludar, despedirse, serEducado);

  // doble y triple
  void (*opMult)(int) = NULL;
  //El apuntar a NULL se puede hacer directo a la funcion, pero es buena practica... 
  //Se puede sustituir el argumento de int por un void
  // void (*opMult)(void) = NULL;
  opMult=imprimirDoble;
  opMult(4);
  opMult=imprimirTriple;
  opMult(4);
  
  // sumar y restar
  int (*procesar)(int, int) = sumar;
  printf("Sumar: %d\n", procesar(7, 3));
  procesar = restar;
  printf("Resta: %d\n", procesar(7, 3));

  return 0;
}

//--------------------------------- Parte 1 -----------------------------------
void printMatrix4(int matrix[][3], int rows) {
  printf("%p\n", matrix);
  printf("%p\n", *matrix);
  printf("%p\n", &matrix[0][0]);

  /*
  matrix es un **
  ptr es un *
  **matrix!=*ptr es incorrecto
  Como es bidimensional se puede hacer esta igualacion de
 *ptr=*matrix
  printf("%p\n", &matrix[0][0]);
  printf("%p\n", &matrix[0][1]);
  printf("%p\n", &matrix[0][2]);
  printf("%p\n", &matrix[1][0]);
  printf("%p\n", &matrix[1][1]);
  printf("%p\n", &matrix[1][2]);
  printf("%p\n", &matrix[2][0]);
*/
  // Van corriditos, en serie, de diferencia de 4 bytes
  // Esta operacion se puede sustituir con un for para recorrer un apuntador a
  // sus direcciones
  int *ptr = *matrix; // &matrix[0][0];
  for (int i = 0; i < 3 * rows; i++) {
    printf("%d\n", *ptr);
    ptr++;
  };
}

//--------------------------------------------------------------------------------
void initValues(float *farray[], int N, float value) {
  int i;
  for (int i = 0; i < N; i++) {
    if (*(farray + i) == NULL)
      continue;
    // *farray[i] = value;
    **(farray + i) = value;
  }
}

int main6() {
  float f1 = 3.14, f2 = -6.5, f3 = 12.8;
  float *farray[5] = {&f1, &f2, &f3};
  float f4 = 0.5;
  farray[3] = &f4;
  int i;
  for (i = 0; i < 5; i++) {
    if (farray[i] == NULL)
      continue;
    printf("%p, %f\n", farray[i], *farray[i]);
    *farray[i] = 0;
  }

  // Modificamos f1:
  **farray = 0.23;
  *farray[0] = 1.23;
  farray[0][0] = 2.23;
  // **farray     = 0.23; Se refiere a la aritmetica de apuntadores
  //*farray[0]   = 1.23; La forma natural de un apuntador en arreglo
  // farray[0][0] = 2.23; La forma como de coordenadas en el espacio de memoria
  // en el array, NO SIEMPRE EL MAS EFICIENTE

  // Modificamos f2:
  **(farray + 1) = 0.35;
  *farray[1] = 1.35;
  farray[1][0] = 2.35;

  initValues(farray, 4, 3.1416);

  printf("f1 = %f\n", f1);
  printf("f2 = %f\n", f2);
  printf("f3 = %f\n", f3);
  printf("f4 = %f\n", f4);

  //--------------------------------- Parte 1
  //-----------------------------------
  int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  /* 1
     2
     3
     4
     5
     6
     7 ... */
  printMatrix4(matrix, 4);

  return 0;
}
