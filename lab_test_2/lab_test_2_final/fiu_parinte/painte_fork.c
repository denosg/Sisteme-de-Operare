#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  int pid,stare;
  printf("Painte: inaten de fork()\n");
  if ( (pod=fork()) !=0)
      wait( &stare);
  else 
      execl("./fiu",0);
  
printf("Parinte: dupa fork()\n");
printf("\tID proces fiu=%d; Terminat cu val %d=%x\n", pid, stare, stare);  
     return 0;
}
