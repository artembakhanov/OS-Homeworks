#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define mb_10 10 * 1024 * 1024

int main(void) {
	struct rusage usage;
	for (int i = 0; i < 10; ++i) {
		char *a = malloc(sizeof(char) * mb_10);
		memset(a, 0, mb_10);
		getrusage(RUSAGE_SELF, &usage);
		printf("usage: %ld\n", usage.ru_maxrss);
		printf("nvs: %ld\n", usage.ru_nivcsw);
		sleep(1);
	}
	
	return 0;
}