#include <stdio.h>

void exo1(){
  int c= getchar()+3;
  while (c  != EOF) {
    if (c == 16 || c == 35) {
      c-=3;
    }
    putchar(c);
    c= getchar()+3;
  }
  printf("\n");
}

void exo2(){
  int choix;
  const int a = 0xFFFFFFFE;
  const int b = 1;
  unsigned int c = 0xFFFFFFFE;
  unsigned int d = 1;
  printf("Partie 1 ou 2 ?\n");
  scanf("%d", &choix);
  switch (choix) {
    case 1:
      printf("%d\n", a+b);
    break;
    case 2:
      printf("%d\n", c+d);
    break;
  }
}

void exo3(){
   int n, quotient, reste, choix;
   printf("Entrez un entier...\n");
   scanf("%d", &n);
   printf("Partie 1 ou 2 ?\n");
   scanf("%d", &choix);
   switch (choix) {
     case 1:
       quotient = n >> 1;
       reste = n & 1;
     break;
     case 2:
       quotient = n >> 2;
       reste = n & 3;
     break;
   }
   printf("quotient = %d\n", quotient);
   printf("reste = %d\n", reste);
}

unsigned int rotationdroite3(unsigned int nb){
 for(int i = 0; i<3; i++) nb = (nb >> 1)^((nb & 1) << 7);
 return nb;
}

unsigned int rotationdroite(unsigned int nb, int decalage){
  while (decalage--) nb = (nb >> 1)^((nb & 1) << 7);
  return nb;
}

void affichage_binaire(unsigned int n){
  int i;
  printf("%d en binaire : ", n);
  for (i = 7; i >= 0; i--) printf("%d", (n >> i ) & 1);
  printf("\n");
}

void exo4(){
  unsigned int n;
  int decal;
  printf("Entrez un entier...\n");
  scanf("%d", &n);
  if (n<256) {
    printf("De combien voulez-vous le décaler ?\n");
    scanf("%d", &decal);
    printf("%u décallé de %d= %d\n", n, decal, rotationdroite(n, decal));
    affichage_binaire(n);
    affichage_binaire(rotationdroite(n, decal));
  }
  else printf("%d est trop grand.\n", n);
}

int main(int argc, char const *argv[]) {
  int exo;
  printf("Choix exercice\n");
  scanf("%d", &exo);
  switch (exo) {
    case 1:
      exo1();
    break;
    case 2:
      exo2();
    break;
    case 3:
      exo3();
    break;
    case 4:
      exo4();
    break;
  }
  return 0;
}
