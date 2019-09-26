#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void child_func() {
	while (1) {
		printf("I'm alive\n");
		sleep(1);
	}
}

int main() {
	int pid;
	
	if ((pid = fork()) == 0) {
		child_func();
	} else {
		sleep(10);
		kill(pid, SIGINT);
	}

	return 0;
}