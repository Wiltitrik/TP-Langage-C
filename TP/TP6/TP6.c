#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

int compte(const char ext[],const char n_file[]){
  FILE *f;
  char car;
  int cmp=0;

  f=fopen(n_file,"r");

  do{
    car=fgetc(f);
    if(strcmp(ext,"-c")==0){
      cmp++;
    }else{
     if(strcmp(ext,"-w")==0){
       if((car == ' ')||(car == '\n')){
           cmp++;
       }
      }else{
         if(strcmp(ext,"-l")==0){
           if(car == '\n') cmp++;
         }
         else return(EXIT_FAILURE);
      }
    }
  }while(car != EOF);

  fclose(f);

  return cmp;
}

void angle(double r){
  printf("cos(%f.)=%f.\n",r,cos(r));
  printf("sin(%f.)=%f.\n",r,sin(r));
  printf("tan(%f.)=%f.\n",r,tan(r));
}

int simul_de(int n){
  int result;
  srand(time(NULL));
  result=rand() % n + 1;
  return result;
}

void current_time(){
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  strftime (buffer,80,"Il est %H:%M.",timeinfo);
  puts (buffer);

  debcours.tm_hour = 15; debcours.tm_min = 45; debcours.tm_sec = 0;
  debcours.tm_mon = 11;  debcours.tm_mday = 24;
}

int main(int argc, char const *argv[]) {
  time_t timer=time(NULL);
  if(argc==3) printf("%d\n", compte(argv[1],argv[2]));
  else{
    angle(0);
    printf("%d\n", simul_de(10));
    current_time();
  }
  return 0;
}
