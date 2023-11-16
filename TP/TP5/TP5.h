#include <stddef.h>

typedef struct cell{
  int value;
  struct cell* next;
} list_t;


int empty(list_t*);

size_t list_size(list_t*);

void print_list(list_t*);

list_t* push_front(list_t*, list_t**);

list_t* push_back(list_t*, list_t**);

list_t* find(int, list_t*);

list_t* erase(int, list_t**);

list_t* sort(list_t**);
