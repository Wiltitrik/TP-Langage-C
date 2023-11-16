#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "TP5.h"

int empty(list_t* L){
  if(L==NULL) return 1;
  else return 0;
}

size_t list_size(list_t* list){
  list_t* temp = list;
  size_t t=0;
  while (!empty(temp)) {
    t++;
    temp=temp->next;
  }
  return t;
}

void print_list(list_t* list){
  list_t* temp = list;
  while (!empty(temp)) {
    printf("%d",temp->value);
    temp=temp->next;
  }
  printf("\n");
}

list_t* push_front(list_t* elt, list_t** list){
  elt->next = *list;
  *list = elt;
  return *list;
}

list_t* push_back(list_t* elt, list_t** list){
  list_t* temp = *list;
  while (!empty(temp->next)) temp = temp->next;
  temp->next = elt;
  *list = temp;
  return *list;
}

list_t* find(int value, list_t* list){
  list_t* temp = list;
  while (!empty(temp)){
    if(temp->value == value) return temp;
    temp = temp->next;
  }
  return NULL;
}

list_t* erase(int value, list_t** list){
  list_t* it = *list;
  list_t* prev = *list;

  while(!empty(it)){
    if(it->value == value){
      if(it == *list){
        *list = it->next;
        it->next = NULL;
        return it;
      }
      prev->next = it->next;
      it->next=NULL;
      return it;
    }
    if(it != *list) prev=prev->next;
    it = it->next;
  }
  return NULL;
}

list_t* sort(list_t** list){}
