#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void main() {

	int pid, stare;
	printf("Parinte inainte de fork()\n");
	if ((pid=fork()) != 0)
		 wait(&stare);
	else	
		execl("./fiu", "./fiu", NULL);
	printf("Parinte: dupa fork()\n");
	printf("\tId proces fiu=%d; Terminat cu valoarea %d=%x\n", pid, stare, stare);

}
