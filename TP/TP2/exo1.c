#include <stdio.h>

int main(int argc, char const *argv[]) {
  int c= getchar()+3;
  while (c  != EOF) {
    if (c == 16 || c == 35) {
      c-=3;
    }
    putchar(c);
    c= getchar()+3;
  }
  printf("\n");
  return 0;
}
