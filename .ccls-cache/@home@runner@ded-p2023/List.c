#include <stdlib.h>
#include "List.h"

struct strNode {
  Type data;
  struct strNode *prior, *next;
};

typedef struct strNode* Node;

struct strList {
  Node first, last;
  int size;
  void (*destructor) (void*);
};

List list_create(void (*destructor)(void*)) {
  List L = (List) malloc(sizeof(struct strList));
  L->first=NULL;
  L->last=NULL;
  L->size=0;
  L->destructor=destructor;
  return L;  
}

void list_destroy(List list) {
  Node current = list->first;
  //recorre los elementos
  while (current != NULL) {
    Node temp = current;
    current = current -> next;  // Línea muy común al recorrer listas enlazadas
    if (list->destructor != NULL) {
      list->destructor (temp->data);
    } //Victor Manuel Telles Amezcua -> VMTA
    free(temp);
  }
  free(list);
}

int list_size(List list) {
  return list->size;
}

void list_add(List list, Type data) {
  Node node = (Node) malloc(sizeof(struct strNode));
  node->data = data;
  if(list->size == 0) {
    node->prior = NULL;
    list->first = node;
  }
  else { 
    node->prior = list->last;
    list->last->next = node;
  }  
  list->last = node;
  node->next = NULL;  
  list->size++;
}

Type list_get(List list, int index) {
  if(index < 0 || index >= list->size) return NULL;
  Node current = list->first;
  // i < index - 1, ejecuta una iteración menos que i < index
  // si quiero el dato con index=3, tengo que realizar 3 movimientos a next
  // si quiero el dato con index=0, tengo que realizar 0 movimientos, quedando en first
  for (int i = 0; i < index; i++) { 
    current=current->next;
  }  
  return current->data;
}

// parece que get() y set() ya están listos, uno con for y otro con while, equivalentes
// Andres V
void list_set(List list, Type data, int index) {
  if(index >= 0 && index < list->size) {
    Node current = list->first;
    int i = 0;
    while (i < index) {
      current = current -> next;
      i++;
    }
    current->data = data;
  }
}

Type list_remove(List list, int index) {
  if(index < 0 || index >= list->size) return NULL;
  // ¿me escuchan?  
  //  a) Sólo hay un elemento en la lista (first y last se hacen NULL)
  if(list->size == 1) {
    // Hay que respaldar el primero antes de igualarlo a nulo, y devolver su dato
    
    list->first = NULL;
    list->last = NULL;
  }
  //  b) Es el primero de la lista (first cambiaría), lo sabes por el ÍNDICE
  else if(index == 0) {
    // El segundo será el nuevo primero
    // Hay que eliminar de memoria al viejo primero, y devolver su dato
    Node second = list->first->next;  // qué te parece este nombre? 
    second->prior = NULL;             // debe ser equivalente a lo que hiciste 
    Type data =  list->first->data;
    // ojo: no se elimina el apuntador first, se elimina el bloque apuntado por first
    free(list->first);               
    list->first = second;    // es importante que esta línea esté después que la 104, 105, 107
    list->size --;
    return data;
    //Itzel Uribe
  }
  //  c) Es el último de la lista (last cambiaría)
  else if(index == list->size - 1) {
    // El penúltimo será el nuevo último
    // Hay que eliminar de memoria al viejo último, y devolver su dato
    Node penultimo=list->last->prior;
    penultimo->next=NULL;
    Type data=list->last->data;
    free(list->last);
    list->last=penultimo;
    list->size --;
    return data;
    //Itzel Uribe
  }
    
  //  d) Está en la mitad de la lista (los vecinos prior y next se conectan)
  else {
    Node current = list->first;
    for(int i = 0; i < index;i++) {
      current=current->next;
    }
    (current->next)->prior = current->prior;
    (current->prior)->next = current->next;
    list->size--;
    Type data = current->data;
    free(current);
    return data;
  }
  //Itzel Uribe

}


// Missael: Segun yo un remove no deberia retornar, una opcion sin retorno
void list_remove2(List list, int index) {
  if(list->size >= 0 && list->size < index){
    Node current = list->first;
    if(index==0){
      if(list->size==0){
        list->first=NULL;
        list->last=NULL;
        free(current);
      } else{
        list->first->next->prior = NULL;
        list->first = current->next;
        free(current);
      }
    }
    else if(index==list->size-1){
      current = list->last;
      list->last->prior->next = NULL;
      list->last = current->prior;
      free(current);
    }
    else {
      for(int i=0; i<index; i++){
        current = current->next;
      }

      current->prior->next = current->next;
      current->next->prior = current->prior;

      free(current);
    }
    list->size--;
  }
}