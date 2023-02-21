
#include <stdio.h>
#include "math.h"

  // --------------------------- Parte F --------------------------------
void printMatrix1(int matrix[3][3]) {
  int r, c;
  for(r = 0; r < 3; r ++) {
    for(c = 0; c < 3; c ++) {
      printf("%d\t", matrix[r][c]);
    }
    printf("\n");
  }
  printf("\n");
}

void printMatrix2(int matrix[][3], int rows) {
  int r, c;
  for(r = 0; r < rows; r ++) {
    for(c = 0; c < 3; c ++) {
      printf("%d\t", matrix[r][c]);
    }
    printf("\n");
  }
  printf("\n");
}

// void printMatrix3(int matrix[][], int rows, int columns) {  No válido
void printMatrix3(int** matrix, int rows, int columns) {   // matrix se creó con memoria dinámica
  
}

void printAll(char words[][20], int N) {
  int i;
  for(i = 0; i < N; i ++) {
    printf("%s\n", words[i]);
  }
}

int main55() {
  char name[][20] = { "Jorge", 
                      "Roberto", 
                      "Arias", 
                      "Ortega" };
  printAll(name, 4);
  
  int array[] = {1, 2, 3, 4};  
  int matriz[][3]  = { {1, 2, 3}, 
                       {4, 5, 6},
                       {7, 8, 9},
                      {10, 11, 12}};
  matriz[0][1]= 8; //{ {1, 8, 3}, 
  //Impresiones
  printMatrix1(matriz);  
  printMatrix2(matriz, 4);
  return 0;
}

  // --------------------------- Parte B --------------------------------


// Ejercicio 1. Implementa una función length que devuelva el tamaño de una cadena de texto, dada mediante un arreglo de caracteres. Número de caracteres que preceden al caracter fin de cadena. 
// No se permiten utilizar funciones externas (strlen). Tampoco se permite utilizar corchetes
int length1(char string[]){
  int i=0;
  while(string[i] != '\0'){
    i++;
  }
  return i;
}

int length2(char *string) {
  int i=0;
  while(*string != '\0') {
    i++;
    string++;
  }
  return i;
}

int length3(char *string) {
  int i=0;
  //Esta incrementando el *string y el indice en conjunto
  while(*(string + i) != '\0') {
    i++;
  }
  return i;
}

  // --------------------------- Parte C --------------------------------


// Ejercicio 2. Implementa una función "swap" capaz de intercambiar el valor entre dos números enteros de 32 bits a, b recibidos.
void swap(int *a, int *b){
  int tmp = *b;
  *b = *a;
  *a = tmp;

  //  A   - |40|
  //  B   - |35|
  //  tmp - |40|
}

  // --------------------------- Parte D --------------------------------


struct strVec2 {
  double x, y;
};
typedef struct {
float x;
float y;
}Vec2;

// Ejercicio 3. Implemente una función toUnit que reciba un vector 2d V (estructura con 2 atributos float ) y lo convierta en vector unitario
void toUnit(Vec2 *v) {
  // pow(6, 3) --> 6 * 6 * 6 = 6^3
  float magnitude = sqrt(pow(v->x, 2) + pow(v->y, 2));
  v->x /= magnitude;
  v->y /= magnitude;
}

// --------------------------- Parte D --------------------------------
int main5() {
  Vec2 v = {4, 3};
  /* |           . (4,3)
     |         
     |
     |__1__2__3__4__>
      |(4, 3)| = Raiz(4*4 + 3*3) = Raiz(16 + 9) = 5
      |(4/5, 3/5)| = |(.8, .6)| = Raiz(0.64 + 0.36) = Raiz(1) = 1
  */
  
  toUnit(&v);
  printf("toUnit: x = %.2f y = %.2f\n", v.x, v.y);
  
  int a = 35, b = 40;
  swap(&a, &b);
  printf("%d, %d\n", a, b);

    // --------------------------- Parte B --------------------------------

  int L1 = length1("Crea una variable p1 que apunte a un número real ");    
  printf("L1: %d\n", L1);
  int L2 = length2("Crea una variable p1 que apunte a un número real "); 
  printf("L2: %d\n", L2);
  int L3 = length3("Crea una variable p1 que apunte a un número real "); 
  printf("L3: %d\n", L3);
  
  char word1[30] = "repl.it";  // word1[7]='\0'
  char word2[] = "repl.it";    // word2[7]='\0'
  //Imprime caracteres
  printf("%d, %d\n", length3(word1), length3(word2));
  //Imprime el tamaño de memoria (almacenamiento)
  printf("%d, %d\n", (int) sizeof(word1), (int) sizeof(word2));
  //printf("%d, %d\n", (int) sizeof(word1)*en esta parte esta contando todos los null o basura, (int) sizeof(word2)-1*aqui seria el valor descontando el caracter null);

  // --------------------------- Parte A --------------------------------
  /*
  a) Crea una variable p1 que apunte a un número real de 64 bits r1 cuyo valor inicial es 7.528 [2 líneas]
  b) Imprime en consola el valor de p1 y su dirección de memoria [1 línea]
  c) Divida entre dos el valor apuntado por p1 [1 línea]
  d) Crea un arreglo a1 con capacidad para 100 enteros de 16 bits y con valor inicial de 0 para cada uno [1 línea]
  e) Crea una variable p3 que apunte al 3er elemento de a1 y asígnale 8 [2 líneas]
  */
  //a
  double r1=7.528;
  double *p1 = &r1;//eddie

  //b) //Victor Telles
  printf ("*valor p1: %.2f, Direccion &p1: %p\n", *p1,&p1);
  
  //c - Missael
  *p1 /= 2;
  printf ("r1 = %.2f\n", r1);
  
  //d)
  //Itzel
  short int arraya1[100]={0};
  
  //e - Missael
  short *p3 = &arraya1[2];
  *p3 = 8;
  printf("Elemento 3 de arraya1 = %d\n", arraya1[2]);
  
  return 0;
}