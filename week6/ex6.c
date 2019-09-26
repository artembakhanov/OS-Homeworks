#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int p[2];

void child_func1() {
	printf("[ch1] created\n");
	int pid2;
	read(p[0], &pid2, sizeof(pid2));
	printf("[ch1] pid2 is read. pid2=%d\n", pid2);
	printf("[ch1] sleeping for some time\n");
	sleep(2);
	
	printf("[ch1] sending SIGSTOP to ch2\n");
	kill(pid2, SIGSTOP);
	printf("[ch1] sleeping for some time\n");
	sleep(2);
	
	printf("[ch1] sending SIGCONT to ch2\n");
	kill(pid2, SIGCONT);
	printf("[ch1] sleeping for some time\n");
	sleep(2);
	
	printf("[ch1] sending SIGTERM to ch2\n");
	kill(pid2, SIGTERM);
	printf("[ch1] exiting...\n");
}

void child_func2() {
	printf("[ch2] created\n");
	while(1) {
		printf("[ch2] I am still alive!\n");
		sleep(1);
	}
	printf("[ch2] exiting...\n");
}

// P - parent; ch1 - child 1; ch2 - child 2;
int main() {
	int pid1, pid2;

	// create a pipe
	if (pipe(p) < 0) {
		printf("Cannot create a pipe. Exiting...");
		exit(1);
	}

	// create the first child
	if ((pid1 = fork()) == 0) {
		//child_func1();
		child_func1();
		exit(0);
	}

	//create the second child
	if ((pid2 = fork()) == 0) {
		child_func2();
		exit(0);
	}

	write(p[1], &pid2, sizeof(int));
	printf("[P] pid 2 is written on pipe. pid2=%d\n", pid2);

	printf("[P] waiting till state of ch2 is changed...\n");
	waitpid(pid2, NULL, 0);
	
	printf("[P] waiting till ch1 is finished...\n");
	waitpid(pid1, NULL, 0);
	printf("[P] exiting...\n");
	return 0;
}