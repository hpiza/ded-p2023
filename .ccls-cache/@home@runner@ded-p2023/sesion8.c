#include <stdio.h>
#include <string.h>

typedef struct {
  int day, month, year;
} Date;

// Podemos definir un alias que reemplace la declaración de un apuntador.
typedef Date* PDate;



typedef void (*PrintDateF) (PDate);  // <-- ¿qué cambiamos aquí?
  // No es necesario una línea nueva

// Ejercicio 3. Modifica las funciones printShortDate y printDates para que trabajen con apuntadores a Date.

void printShortDate(PDate date) {
  printf("%02d/%02d/%02d\n", date->day, date->month, date->year%100); 
}

// Ejercicio 4. Creea una función printMediumDate que imprima la fecha utilizando el formato mediano: 27 de diciembre de 2020: "27 Dic 2020". 
void printMediumDate(PDate date){
  char months[][4] = { {'E', 'n', 'e', '\0'}, 
                       "Feb", "Mar", "Abr", 
                       "May", "Jun", "Jul",
                       "Ago", "Sep", "Oct", "Nov", "Dic"};
  printf("%d %s %d\n", date->day, months[date->month-1], date->year); 

  char month[4];
  switch(date->month) {
    case 1: strcpy(month, "Ene"); break;
    case 2: strcpy(month, "Feb"); break;
    case 3: strcpy(month, "Mar"); break;
    case 4: strcpy(month, "Abr"); break;
  }
  printf("%d %s %d\n", date->day, month, date->year);   
} 

static void printDates(PDate dates[], int N, PrintDateF printDate) {
  int i;
  for(i = 0; i < N; i ++) printDate(dates[i]);
  printf("----------\n");
}

void printNothing(PDate date) {
  printf("Nothing\n");
}

int main8() {
  Date date1 = {7,  2, 2023};
  Date date2 = {15, 4, 1973};
  Date date3 = {24, 6, 1998};
  Date date4 = {8, 11, 2003};
  PDate dates1[] = { &date1, &date2 , &date3, &date4 };
  
  Date  dates2[] = {{17, 3, 2023}, {25, 4, 1983}, {24, 6, 1998}, {8, 11, 2003}};
  PDate dates3[] = { &dates2[0], &dates2[1], &dates2[2], &dates2[3] };

  printDates(dates1, 4, printShortDate);
  printDates(dates3, 4, printShortDate);
  printDates(dates1, 4, printMediumDate);
  printDates(dates3, 4, printMediumDate);
  printDates(dates1, 4, printNothing);
}

/*
Ejercicio 5. Implementa una función compareFloat que reciba dos apuntadores a flotantes y que devuelva un número entero: -1 si el primer flotante apuntado es menor que el segundo, 1 si el primer flotante apuntado es mayor que el segundo, 0 si el primer flotante apuntado es igual que el segundo.
*/

static int compareFloat(float *numero1, float *numero2) {
  if(*numero1 > *numero2)
    return 1;
  
  if(*numero1 == *numero2)
    return 0;
  
  return -1;
}


/*
Ejercicio 6. Implementa una función compareInt que reciba dos apuntadores a enteros y que devuelva un número entero: negativo, positivo o cero. No utilices la sentencia if */
static int compareInt(int *a, int *b) {
  return *a - *b;
}

/*
Ejericio 7. Implementa una función compareDate que reciba dos apuntadores a Date y que devuelva un número entero. Prueba su funcionamiento con estas fechas:
Date d1 = { 27, 8, 2020 }, d2 = { 15, 12, 2008 }, d3 = { 27, 8, 2020 }; */
static int compareDate(PDate DateOne, PDate DateTwo){
  int result[3] = { DateOne->year - DateTwo->year, DateOne->month - DateTwo->month, DateOne->day - DateTwo->day };
  if(result[0] != 0) return result[0];
  if(result[1] != 0) return result[1];    
  return result[2];
  /*
  if(DateOne->year  != DateTwo->year)  return DateOne->year - DateTwo->year;
  if(DateOne->month != DateTwo->month) return DateOne->month - DateTwo->month;
  return DateOne->day - DateTwo->day; */
}


int main8a(){
  // Ejercicio 5. 
  float x = 3.4, y = 4.8, z = 4.8;
  printf("%d, %d, %d\n", compareFloat(&x, &y), compareFloat(&y, &x), compareFloat(&y, &z));

  // Ejercicio 6. 
  int a = 3, b = 4, c = 3;
  printf("%d, %d, %d\n", compareInt(&a, &b), compareInt(&b, &a), compareInt(&a, &c));
  
  // Ejercicio 7
  Date d1 = { 27, 8, 2020 }, d2 = { 15, 12, 2008 }, d3 = { 27, 8, 2020 };
  int compDate = compareDate(&d1, &d2);
  printf("%d\n", compDate);
  printf("%d\n", compareDate(&d1, &d3));
  d1.day = 26;
  printf("%d\n", compareDate(&d1, &d3));

  // int compareFloat(float *numero1, float *numero2) {
  int (*compareAny) (float*, float*);
  //int (*compareAny)(void*, void*)
  compareAny = compareFloat;
  printf("%d, %d, %d\n", compareAny(&x, &y), compareAny(&y, &x), compareAny(&y, &z));

 // compareAny = compareInt;
 // compareAny = compareDate;
  
  return 0;
}
