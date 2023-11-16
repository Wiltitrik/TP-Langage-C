#include <stdio.h>
#include <stdlib.h>

int palindrome(char mot[],int lg, int i){
  return ((i=lg/2) || (mot[i] == mot[lg-i-1]) && palindrome(mot,lg, i+1));
}

void exo1(){
  int i = 0;
  char tab[10];
  char c = getchar();
  while((c != EOF)&&(i<10)){
    tab[i] = c;
    i++;
    c = getchar();
  }
  if(palindrome(tab, 10, 1)) printf("\n%s est un palindrome\n", tab);
  else printf("%s inversé: ", tab);
  while (i>0) {
    printf("%c", tab[i]);
    i--;
  }
  printf("\n");
}

int cherche(char chaine[], char c, int i){
  return((chaine[i] == c) ||(chaine[i] != '\0') && cherche(chaine, c, i+1));
}

void exo2(){
  int i=0;
  char tab[50];
  printf("Entre une chaîne de caractères\n");
  char c = getchar();
  while (c != EOF) {
    tab[i] = c;
    i++;
    c = getchar();
  }
  printf("\nCaractère à rechercher ?\n");
  c = getchar();
  printf("%d\n", cherche(tab, c, 0));
}

void Affiche3(char ** tab,int lg){
  for(int i = 0; i < lg; i++) {
    printf("\n-------------\n" );
    for(int j = 0; j < lg; j++) {
      printf("| %c ", tab[i][j]);
    }
    printf("|");
  }
  printf("\n-------------\n" );
}

void Affiche5(char ** tab,int lg){
  for(int i = 0; i < lg; i++) {
    if(lg == 3) printf("\n-------------\n" );
    else if(lg == 5) printf("\n---------------------\n" );
    for(int j = 0; j < lg; j++) {
      printf("| %c ", tab[i][j]);
    }
    printf("|");
  }
  if(lg == 3) printf("\n-------------\n" );
  else if(lg == 5) printf("\n---------------------\n" );
}

char ** init(int n){
  char ** carte = malloc(n*sizeof(char*));
  for (int i = 0; i < n; i++) {
    carte[i] = malloc(n*sizeof(char));
    for(int j = 0; j < n; j++) {
      carte[i][j]=' ';
    }
  }
  return carte;
}

int verifligne(char ** chaine, char c, int l){
  int i=0, j=0, ligne=0;
  while (!ligne && i<l) {
    if (j == l) ligne=1;
    else{
      if(chaine[i][j] == c) j++;
      else{
        i++;
        j=0;
      }
    }
  }
  return ligne;
}

int verifcol(char ** chaine, char c, int l){
  int i=0, j=0, colonne=0;
  while (!colonne && j<l) {
    if (i == l) colonne=1;
    else{
      if(chaine[i][j] == c) i++;
      else{
        j++;
        i=0;
      }
    }
  }
  return colonne;
}

int verifdiag(char ** tab, char c, int lg)
{
    int i=0, j=0, diagonale=1;
    while((i<lg) && diagonale==1)
    {
        if(tab[i][i] != c)
        {
            diagonale = 0;
        }
        i++;
    }
    if (diagonale==0)
    {
        diagonale=1;
        i=lg-1;
    }
    while((i>-1) && diagonale==1)
    {
        if((j<lg) && diagonale==1)
        {
            if(tab[i][j] != c)
            {
                diagonale = 0;
            }
            j++;
        }
        i--;
    }
    return diagonale;
}

int complet(char ** chaine, int lg){
  int jeu = 0, i=0, j=1;
  while(jeu && i<lg){
    while (jeu && j<lg) {
      if(chaine[i][j] == ' ') jeu = 0;
      j++;
    }
    i++;
  }
  return jeu;
}

int partie(char ** chaine, char c, int lg){
  if(verifligne(chaine, c, lg)||verifcol(chaine, c, lg)||verifdiag(chaine, c, lg)) return 1;
  else return 0;
}


void remplir(char ** tab, int lg){
  char c;
  int joueur=0, ligne, colonne, jeu=1;
  while (jeu) {
    system("clear");
    if (lg == 3) Affiche3(tab, lg);
    else if (lg == 5) Affiche5(tab, lg);
    printf("Joueur %d entrez une ligne:\n",1+joueur%2);
    scanf("%d", &ligne);
    printf("Joueur %d entrez une colonne:\n",1+joueur%2);
    scanf("%d", &colonne);
    if(joueur%2 == 1) c='X';
    else c='O';
    system("clear");
    if (tab[ligne-1][colonne-1]== ' '){
      tab[ligne-1][colonne-1] = c;
      joueur++;
    }
    else printf("Cette case est déjà occupée...\n");
    if (partie(tab, c, lg)){
      printf("Le joueur %c a gagné la partie\n", c);
      jeu=0;
    }
    else{
      if(complet(tab, lg)){
        printf("match nul\n");
        jeu=0;
      }
    }
  }
}

void exo3(){
  int c;
  scanf("%d", &c);
  if((c == 3) || (c == 5)){
    char ** tab = init(c);
    remplir(tab, c);

  }
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
  }
  return 0;
}
