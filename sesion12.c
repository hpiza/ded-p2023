#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 40

void printMatrix(float** matrix, int rows, int columns) {
  for(int i=0; i<rows; i++) {
      for(int j=0; j<columns; j++) {
          printf("M[%d][%d] = %.2f\n", i, j, matrix[i][j]);
        }
      printf("\n");
  }
}

float** transpose(float** matrix, int rows, int columns){
  float **tempMatrix;
  tempMatrix = (float**) malloc(columns*sizeof(float*));
  
  for(int i=0; i<columns; i++){
    tempMatrix[i] = (float*) malloc(rows * sizeof(float));
    for(int j=0; j<rows; j++){
      tempMatrix[i][j] = matrix[j][i];
      }
    }

  return tempMatrix;
}
// Bloque 2 de ejercicios:
// 1. Solicite el número de filas R y columnas C que tendrá una matriz de flotantes.
// 2. Crea la matriz con memoria dinámica
// 3. Crea un método que devuelva la transpuesta de una matriz de R x C


int main() {
  //1. 
  int rf,cf;
  printf("Ingrese el numero de filas: ");
  scanf("%d", &rf);
  printf("Ingrese el numero de columnas: ");
  scanf("%d", &cf);
  float** matrix;
  matrix = (float**) malloc(rf * sizeof(float*));
  for(int i = 0; i<cf; i++){
    matrix[i] = (float*) malloc(cf * sizeof(float));
  }
  printMatrix(matrix, rf, cf);
  float** tr = transpose(matrix, rf, cf);
  printMatrix(tr, cf, rf);
  
  return 0;
}

int main12() {
  //------------------------------------------------------
  // char matrix[ROWS][COLS]; Matriz en memoria estática
  
  // Matrices con memoria dinámica
  char** matrix;
  int rows = 10, cols = 40;
  matrix = (char**) malloc(rows * sizeof(char*));
  printf("%p %p\n", matrix, &matrix);
  // matrix -->|0|--> o
  //           |1|--> o
  //           |2|--> o
  //            :
  //           |9|--> o
  int r, c;
  for(r = 0; r < rows; r ++) {
    matrix[r] = (char*) malloc(cols * sizeof(char));
    printf("%p  %p\n", &matrix[r], matrix[r]);
  }
  //------------------------------------------------------
  //                   0  1  2  3      39
  // matrix -->|0|--> {0, 0, 0, 0, ..., 0}
  //           |1|--> {0, 0, 0, 0, ..., 0}
  //           |2|--> {0, 0, 0, 0, ..., 0}
  //            :
  //           |9|--> {0, 0, 0, 0, ..., 0}
  char ch;
  for(r = 0; r < rows; r ++) {
    ch = 'A';
    for(c = 0; c < cols; c ++) {
      matrix[r][c] = ch ++;   
    }
  }
  for(r = 0; r < rows; r ++) {
    for(c = 0; c < cols; c ++) {
      printf("%c", matrix[r][c]);
    }
    printf("\n");
  }
  // Liberar el espacio ocupado por la matriz
  for(r = 0; r < rows; r ++) free(matrix[r]);
  free(matrix);
//------------------------------------------------------
  rows = 5;
  char** matrix2 = (char**) malloc(rows * sizeof(char*));
  matrix2[0] = malloc( 64 * sizeof(char));  // Memoria ocupada: 64B
  matrix2[1] = malloc( 32 * sizeof(char));  // Memoria ocupada: 32B
  matrix2[2] = malloc( 32 * sizeof(char));  // Memoria ocupada: 32B
  matrix2[3] = malloc(128 * sizeof(char));  // Memoria ocupada: 144B
  matrix2[4] = malloc(160 * sizeof(char));  // Memoria ocupada: 160B
  //------------------------------------------------------
  for(r = 0; r < rows; r ++) {
      printf("%p\n", matrix2[r]);
  }  
  //------------------------------------------------------
  //                   0  1  2
  // matrix2-->|0|--> {0}
  //           |1|--> {0, 0}
  //           |2|--> {0, 0, 0}
  //           |3|--> {0, 0}
  //           |4|--> {0}
  matrix2[0][0] = 'a';
  matrix2[1][0] = 'b';  matrix2[1][1] = 'c';
  matrix2[2][0] = 'd';  matrix2[2][1] = 'e'; matrix2[2][2] = 'f';
  matrix2[3][0] = 'g';  matrix2[3][1] = 'h';
  matrix2[4][0] = 'i';
  
  return 0;
}