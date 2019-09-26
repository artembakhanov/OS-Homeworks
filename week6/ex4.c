#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// The result is expected. We ask the process to quit with user defined signal.
// Handler for this signal is defined -> it is called. 

void sihand(int signal) {
	printf("Terminated\n");
	exit(signal);
}

void skhand(int signal) {
	printf("SIGKILL!!1\n");
	exit(signal);
}

void sshand(int signal) {
	printf("SIGSTOP!!1\n"); // but it cannot be caught! why did you ask me to write it?
}

void su1hand(int signal) {
	printf("SIGUSR1 !!1\n");
	exit(signal);
}


int main() {
	printf("Started working on really hard task...\n");
	fflush(stdout);
	struct sigaction siact = { sihand };
	struct sigaction ssact = { sshand };
	struct sigaction skgact = { skhand };
	struct sigaction su1act = { su1hand };
	
	sigaction(SIGINT, &siact, NULL);	
	sigaction(SIGSTOP, &ssact, NULL);	
	sigaction(SIGKILL, &skgact, NULL);	
	sigaction(SIGUSR1, &su1act, NULL);	
	while(1);

	return 0;
}