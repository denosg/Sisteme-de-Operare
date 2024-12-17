#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void main() {
	int pid;
	printf("Fiul: incepe executia\n");
	pid=getpid();
	printf("Fiul: %d se termina\n", pid);
	exit(pid);
}
