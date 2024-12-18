#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
 int pid;
 printf("Fiul: incepe excutia \n");
 pid=getpid();
 printf("fiul: %d se termina \n ", pid);
 exist(pid);
return 0;
}
