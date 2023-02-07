#include <stdio.h>

typedef enum {False, True} bool;
// Ejercicio 1 (apuntadores a funciones)
// Crea una estructura con alias Date que almacene 3 números enteros de 32 bits: day, month, year.

typedef struct {
  int day, month, year;
} Date;

typedef void (*PrintDateF) (Date);

// Crea una función printShortDate que imprima una fecha dada por un ejemplar Date en formato corto. Ejemplos:
//  • 27 de diciembre de 2020: 27/12/20
//  • 15 de enero de 2016: 15/01/16
//  • 8 de mayo de 2009: 08/05/09

void printShortDate(Date dateStruct){
  printf("%02d/%02d/%02d\n", dateStruct.day, dateStruct.month, dateStruct.year%100);
}

// Recibe: un arreglo de fechas, # de elementos, apuntador a una función de impresión
void printDates(Date dates[], int N, PrintDateF printDate) {
  int i;
  for(i = 0; i < N; i ++) printDate(dates[i]);
}

int main() {
  Date dates[] = { {7, 2, 2023}, {15, 4, 1973}, {24, 6, 1998}, {8, 11, 2003} };
  Date d1; 

  printDates(dates, 4, printShortDate);
}

// Ejercicio 1 (arreglos de apuntadores)
// Dado el siguiente tipo: typedef enum { False, True } bool
// Crea una función equals que reciba dos cadenas de texto, y devuelva True si ambas cadenas son iguales; en caso contrario, devuelva False
//  Dos cadenas son iguales si todos los caracteres en las posiciones correspondientes son iguales, incluyendo al fin de cadena.
// Restricción: el algoritmo implementado no deberá acceder al arreglo con corchetes, ni utilizar números enteros para el control de las iteraciones.

  //---------------------------------------Ejercicio 1----------------------------

bool equals1(char*, char*);
bool equals2(char*, char*);

  //---------------------------------------Ejercicio 2----------------------------

void addOne1(int** arreglo, int n){
  for(int i=0; i<n; i++){
    if(*arreglo != NULL){
      (**arreglo) ++;
    }
    arreglo ++;
  }
}

//Original
void addOne2(int* arreglo[], int n){
  for(int i=0; i<n; i++){
    if(arreglo[i] != NULL){
      (*arreglo[i]) ++;
    }
  }
}

void addOne3(int** arreglo, int n){
  for(int i=0; i<n; i++){
    if(*(arreglo+i) != NULL){
      (**(arreglo+i)) ++;
    }
  }
}

void addOne4(int *arreglo[], int n){
  for(int i=0; i<n; i++){
    if(arreglo[i] != NULL){
      arreglo[i][0] ++;
    }
  }
}

// Ejercicio2. Crear una función addOne que incremente en uno a todos los valores apuntados por un arreglo de enteros recibido, excepto aquellos apuntadores nulos.

int main7() {
  //---------------------------------------Ejercicio 2----------------------------
  int a = 7, b = 8, c = 9;
  int* arreglo[10] = {&a, &b, NULL, &c};
  addOne1(arreglo, 10);
  printf("A=%d, B=%d, C=%d\n", a, b, c);
  addOne2(arreglo, 10);
  printf("A=%d, B=%d, C=%d\n", a, b, c);
  addOne3(arreglo, 10);
  printf("A=%d, B=%d, C=%d\n", a, b, c);
  addOne4(arreglo, 10);
  printf("A=%d, B=%d, C=%d\n", a, b, c);
  
  //---------------------------------------Ejercicio 1----------------------------

  char word[100] = "algoritmo";
  if(equals2("algoritmo", word)) {
    printf ("Es igual\n");
  } else printf("No es igual\n");
}
//nota: cuando manejamos un bool el cero sera siempre False o tambien se puede escribir como !, a cambio un true no importa
bool equals1(char *w1, char *w2) {
  while(*w1 == *w2) {
    if(*w1 == '\0') return True;
    w1 ++;
    w2 ++;
  }
  return False;
}

bool equals2(char *str1, char *str2) {
  while(*str1 != '\0' || *str2 != '\0') {
	// while(*str1 || *str2 != '\0') {
		if(*str1 != *str2) return False;
		str1++;
		str2++;
	}
	return True;
}