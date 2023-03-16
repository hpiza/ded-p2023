#include <stdio.h>

typedef struct strDate {
  int day, month, year;
  struct strDate *self, *next;
  // struct strDate* next;
} Date;

void incYear(Date d) {  // d pasa por valor
  //d.year ++;  // esto no tendrá efecto sobre la estructura original
  d.self->year ++;  // esto si deberá tener efecto
}

void print3Dates(Date d) {
  printf("%d/%d/%d\n", d.day, d.month, d.year);
  Date* current = d.next;
  printf("%d/%d/%d\n", current->day, current->month, current->year);
  current = current->next;
  printf("%d/%d/%d\n", current->day, current->month, current->year);  
}

void printDates(Date *current) {
  while(current != NULL) {
    printf("%d/%d/%d\n", current->day, current->month, current->year);
    current = current->next;
  }
  printf("-------\n");
}

int main() {
  printf("Estructuras autorreferenciales\n");
  Date d0 = {24, 12, 2020, NULL, NULL};
  //printf("%d/%d/%d - %p %p\n", d0.day, d0.month, d0.year, d0.self, d0.next);  
  Date d1 = {16, 3, 2023, NULL, NULL};
  d1.self = &d1;  
  incYear(d1);
  //printf("%d/%d/%d - %p %p\n", d1.day, d1.month, d1.year, d1.self, d1.next);
  struct strDate d2 = {18, 4, 2024, NULL, NULL};
  //printf("%d/%d/%d - %p %p\n", d2.day, d2.month, d2.year, d2.self, d2.next);
  struct strDate d3 = {5, 11, 2018, NULL, NULL};

  d0.next = &d1;
  d1.next = &d2;  
  d2.next = &d3;
  // d0 -> d1 -> d2 -> d3 -> o
  
  printDates(&d3);
  printDates(&d2);
  printDates(&d1);
  printDates(&d0);  
	return 0;
}

