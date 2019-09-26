#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sihand(int signal) {
	printf("Terminated\n");
	exit(signal);
}


int main() {
	printf("Started working on really hard task...\n");
	fflush(stdout);
	signal(SIGINT, sihand);	
	while(1);

	return 0;
}