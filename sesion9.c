#include <stdio.h>
#include <string.h>

typedef struct {
  int day, month, year;
} Date;


// Podemos definir un alias que reemplace la declaración de un apuntador.
typedef Date* PDate;

typedef int (CompareFunc) (void*, void*);

//Ejercicio 5  
static int compareFloat(void* ptr1, void* ptr2) {
  float* numero1 = (float*) ptr1;
  float* numero2 = (float*) ptr2;  
  if(*numero1 > *numero2) return 1;
  if(*numero1 == *numero2) return 0;
  return -1;
}  

static int compareString(void* ptr1, void* ptr2) {
  char* str1 = (char*) ptr1;
  char* str2 = (char*) ptr2;
  return strcmp(str1, str2);
}

//Ejercicio 6 
static int compareInt(void *ptr1, void *ptr2) {
  int* a = (int*) ptr1;
  int* b = (int*) ptr2;  
  return *a - *b;
}

//Ejercicio 7 
static int compareDate(void *ptr1, void *ptr2) {
  Date* DateOne = (Date*) ptr1;//
  Date* DateTwo = (Date*) ptr2;   
  if(DateOne->year  != DateTwo->year)  return DateOne->year - DateTwo->year;
  if(DateOne->month != DateTwo->month) return DateOne->month - DateTwo->month;
  return DateOne->day - DateTwo->day;
}

int maxInt(int array[], int N) {
  int mi = 0;
  int i;
  for(i = 1; i < N; i ++) {
    // if(intArray[i] > intArray[mi]) mi = i;
    if(compareInt(&array[i], &array[mi]) > 0) mi = i;
  }
  return mi;
}

int maxDate(Date array[], int N) {
  int mi = 0;
  int i;
  for(i = 1; i < N; i ++) {
    // if(dateArray[i] > dateArray[mi]) mi = i;
    if(compareDate(&array[i], &array[mi]) > 0) mi = i;
    // if(dateArray[i] < dateArray[mi]) mi = i;
    // if(compareDate(&dateArray[i], &dateArray[mi]) < 0) mi = i;
    // if(dateArray[i] == dateArray[mi]) mi = i;
    // if(compareDate(&dateArray[i], &dateArray[mi]) == 0) mi = i;
  }
  return mi;
}

int max(void* array[], int N, CompareFunc compareFunc) { 
  int mi = 0;
  int i;
  for(i = 1; i < N; i ++) {
    if(compareFunc(array[i], array[mi]) > 0) mi = i;
  }
  return mi;
}

int main() {
  int intArray[] = { 3, 4, 1, 5, 2 };
  int maxIndex = maxInt(intArray, 5);  // maxIndex = 3 (5)
  printf("Max = (index=%d,value=%d)\n", maxIndex, intArray[maxIndex]);
  Date dateArray[] = { {14, 2, 2023}, {25, 6, 1975}, {7, 11, 2033}, {1, 1, 2015}, {30, 10, 1998} };
  maxIndex = maxDate(dateArray, 5);
  printf("Max = %d\n", maxIndex);
  printf("-----------------\n");

  int i1=3, i2=4, i3=1, i4=5, i5=9;
  float f1=1.5, f2=-4.6, f3=8.3, f4=2.5, f5=-7.8;  
  Date d1={14, 2, 2023}, d2={25, 6, 1975}, d3={7, 11, 2033}, d4={1, 1, 2045}, d5={30, 10, 1998};

  void* intPtrArray[]   = {&i1, &i2, &i3, &i4, &i5};
  void* floatPtrArray[] = {&f1, &f2, &f3, &f4, &f5};
  void* datePtrArray[]  = {&d1, &d2, &d3, &d4, &d5};    
  void* strArray[10]    = { "Hola", "Mundo", "Apuntador", "main", "void", "zapato", "int" };  
  
  maxIndex = max(intPtrArray,   5, compareInt);
  printf("Max = %d\n", maxIndex);  
  maxIndex = max(floatPtrArray, 5, compareFloat);
  printf("Max = %d\n", maxIndex);  
  maxIndex = max(datePtrArray,  5, compareDate);
  printf("Max = %d\n", maxIndex);
  maxIndex = max(strArray,      7, compareString);
  printf("Max = %d\n", maxIndex);
  printf("-----------------\n");

  double d = 3.4;
  void* ptr = &d;
  printf("%p\n",  ptr);  
  //double* pd = (double*) ptr;
  //printf("%f\n", *pd);
  printf("%f\n", *((double*) ptr));

  ptr ++;
  printf("%p\n",  ptr);
  
  int x = 10;
  ptr = &x;
  printf("%p\n",  ptr);
  //int* pi = (int*) ptr;
  //printf("%d\n", *pi);    
  printf("%d\n", *((int*) ptr)); 
  
  
  return 0;
}
