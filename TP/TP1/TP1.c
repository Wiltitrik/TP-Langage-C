#include <stdio.h>
#include <math.h>

void exo1(){
  int age;
  printf("Bonjour ! \nEntrez votre âge... \n");
  scanf("%d", &age);
  printf("vous avez %d ans.\n", age);
}

void exo2(){
  float max, a, b;
  printf("Entrez trois réels...\n");
  scanf("%f", &max);
  scanf("%f", &a);
  scanf("%f", &b);
  if(max<a){
    max=a;
    if(max<b){
      max=b;
    }
  }
  printf("la plus grande valeur entrée est %f\n", max);
}

void exo3(){
  int s=0;
  for (int i = 0; i < 10; i++) {
    s+=i;
  }
  printf("La somme des 10 premiers entiers naturels est %d\n", s);
}

void exo4(){
  int x, s, m, i;
  i=0;
  x=0;
  s=0;
  while (x!=-1) {
    printf("Entrez un entier...\n");
    scanf("%d", &x);
    if (x!=-1){
      s+=x;
      i++;
    }
  }
  m=s/i;
  printf("la moyenne des entiers entrés est %d\n", m);
}

void exo5(){
  int x, s;
  x=0;
  s=0;
  while (x!=EOF) {
    printf("Entrez un entier...\n");
    scanf("%d", &x);
    if (x!=EOF) {
      if ((x%2)==0) {
        s+=x;
      }
    }
  }
  printf("La somme des entiers entrés est %d\n", s);
}

void exo6(){
  if (sizeof(int) < -1)
  printf("Bizarre, bizarre ...\n");
  else printf ("Tout semble normal\n");
}

void exo7(){
  int c;
  while (c=getchar() != EOF) {
    if (c != 'e' && c != 'E') {
      putchar(c);
    }
  }
  printf("\n");
}

void exo8(){
  int n, res;
  float fl;
  printf("Entrez un entier...\n");
  scanf("%d", &n);
  fl=(float)n;
  res = (int)(logf(fl)/logf(2));
  printf("La partie entière du logarithme base 2 de %d est %d\n", n, res);
}

void exo9(){
  int n;
  int res=1;
  printf("Entrez un entier...\n");
  scanf("%d", &n);
  if (n>0) {
    for (int i = 1; i <= n; i++) {
      res*=i;
    }
  }
  if (n>=0) printf("La factorielle de %d est %d\n", n, res);
  else printf("La factorielle de %d n'existe pas\n", n);
}

int exo9v2(int n){
  if (n==0) {
    return 1;
  }
  else {
    return n*exo9v2(n-1);
  }
}


int main(int argc, char const *argv[]) {
  int exo, n;
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
    case 5:
      exo5();
    break;
    case 6:
      exo6();
    break;
    case 7:
      exo7();
    break;
    case 8:
      exo8();
    break;
    case 9:
      exo9();
    break;
    case 10:
      printf("Entrez un entier...\n");
      scanf("%d", &n);
      if (n>=0) printf("La factorielle de %d est %d\n", n, exo9v2(n));
      else printf("La factorielle de %d n'existe pas\n", n);
    break;
  }
  return 0;
}
