#include "TP5.h"
#include <stddef.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  list_t a,b;
  a.value= 1;
  a.next=NULL;
  b.value= 2;
  b.next=NULL;
  list_t* c=NULL;
  list_t* supp=NULL;
  c=push_front(&a,&c);
  print_list(c);
  c=push_back(&b,&c);
  print_list(c);
  supp=erase(2,&c);
  print_list(c);
  print_list(supp);
  return EXIT_SUCCESS;
}
