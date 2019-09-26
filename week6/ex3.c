#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sihand(int signal) {
	printf("Terminated\n");
	exit(signal);
}


int main() {
	struct sigaction sigact = { sihand };
	printf("Started working on really hard task...\n");
	fflush(stdout);
	sigaction(SIGINT, &sigact, NULL);	
	while(1);

	return 0;
}