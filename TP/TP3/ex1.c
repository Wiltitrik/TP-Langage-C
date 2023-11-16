#include <stdio.h>

int palindrome(char mot[],int lg, int i){
  return ((i=lg/2) || (mot[i] == mot[lg-i-1]) && palindrome(mot,lg, i+1));
}

void main(){
  int i = 0;
  char tab[10];
  char c;
  c = getchar();
  while((c != EOF)&&(i<10)){
    tab[i]=c;
    i++;
    c = getchar();
  }
  if(palindrome(tab, 10, 1)) printf("\n%s est un palindrome\n", tab);
  else{
    printf("%s n'est pas un palindrome %s inversé: ", tab, tab);
    while (i>=0) {
      printf("%c", tab[i]);
      i--;
    }
    printf("\n");
  }
}
