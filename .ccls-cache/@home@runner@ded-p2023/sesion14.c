#include <stdio.h>
#include <stdlib.h>

/* Ejercicio 1. Crea un método initString que construya una cadena de texto compacta
cuyo contenido sea igual al de un arreglo de caracteres recibido. */

void initString(char** dest, char src[]){
  // int n = strlen(src);
  int n = 0;  
  while (src[n] != '\0') n++;
  *dest = (char*) malloc((n + 1) * sizeof(char));
  // strcpy(*dest, src);
  for (int i=0; i<=n; i++) (*dest)[i] = src[i];
  //(*dest)[n]='\0';
}

/* Ejercicio 2. Declare una función initSockets que reciba por referencia un arreglo de
apuntadores a Sockets y un entero N. La función deberá crear un arreglo capaz de almacenar N apuntadores a sockets. Además deberá crear (en memoria dinámica) los N sockets con los
datos predeterminados: 127.0.0.1:80.
*/

typedef struct {
  unsigned char address[4];
  unsigned short int port;
} Socket;

void initSockets(Socket*** sockets, int N){
  Socket** oSockets = (Socket**) malloc(N * sizeof(Socket*));
  // *sockets = (Socket**) malloc(N * sizeof(Socket*));
  for(int i=0; i<N; i++){
    oSockets[i] = (Socket*) malloc(sizeof(Socket));
    // *sockets[i] = (Socket*) malloc(sizeof(Socket));
    oSockets[i]->port = 80;
    // *sockets[i]->port = 80;
    oSockets[i]->address[0] = 127;
    oSockets[i]->address[1] = 0;
    oSockets[i]->address[2] = 0;
    oSockets[i]->address[3] = 1;
  }
  *sockets = oSockets;
}

void freeSockets(Socket** sockets, int N) {
  for(int i=0; i<N; i++) free(sockets[i]);
  free(sockets);
}

void swap14(int* a, int* b) {
  //int tmp = *a;
  //*a = *b;
  //*b = tmp;
  int aa = *b;
  int bb = *a;
  *a = aa;
  *b = bb;
}

int main1414() {
  // Ejercicio 4. Investigar la capacidad de memoria disponible.
  // En dos ciclos anidados solicitan espacio para 1000 números enteros de 32b.
  //     Ciclos de al menos mil iteraciones cada uno.
  // Si no se pudo reservar, imprime en qué iteración de ambos ciclos sucedió, así
  // como la cantidad de memoria que sí se pudo reservar y termina el programa.
  //   Imprime la memoria en Gigabytes.
  //   Se recomienda acumular la memoria reservada como Megabytes (no como bytes).
  double MB = 0;
  for(int i = 0; i < 100; i ++) {
    for(int j = 0; j < 100; j ++) {
      int* iarray = (int*) malloc(10000 * sizeof(int));
      if(!iarray) {
        printf("Tronó en i=%d, j=%d\n", i, j);
        return 0;
      }
      MB += 10000 * sizeof(int) / 1024.0 / 1024.0;
      for(int k = 0; k < 1000; k ++) iarray[k] = k;
      //printf("Array = %p, %d, %.1f MB\n", iarray, i, MB);
      //free(iarray);
    }
  }  
  double GB = MB / 1024;
  printf("Memoria ocupada: %.1f GB\n", GB);
  
  int n;
  printf("¿Cuántos números quieres? ");
  scanf("%d", &n);
  int* array = (int*) malloc(n * sizeof(int));
  for(int i = 0; i < n; i ++) array[i] = i;
  printf("%p\n", array);
  
  int m;
  printf("¿Cuántos números extra quieres? ");
  scanf("%d", &m);
  array = (int*) realloc(array, (n + m) * sizeof(int));  
  printf("%p\n", array);
  for(int i = n; i < m + n; i ++) array[i] = i;  
  
  for(int i = 0; i < n + m; i ++) {
    printf("%d\n", array[i]);
  }
  
}

int main14() {
  int x = 5, y = 10;
  swap14(&x, &y);
  
  char* target = NULL;
  initString(&target, "Texto de prueba");
  puts(target);
  free(target);
  
  char source[30] = "Otro texto de prueba";
  initString(&target, source);
  puts(target);
  free(target);

  Socket** sockets = NULL;
  const int n = 8;
  initSockets(&sockets, n);
  for(int i = 0; i < n; i ++) {
    //Socket s = *sockets[i];
    //printf("%u.%u.%u.%u:%u\n", s.address[0], s.address[1], s.address[2], s.address[3], s.port);
    Socket* s = sockets[i];
    printf("%u.%u.%u.%u:%u\n", s->address[0], s->address[1], s->address[2], s->address[3], s->port);
  }
  freeSockets(sockets, n);
  
  return 0;
}
