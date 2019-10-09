#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define mb_10 10 * 1024 * 1024

// so and si are 0 because we never use disk in this case. 
// we have enough main memory for this program.
int main(void) {
	for (int i = 0; i < 10; ++i) {
		char *a = malloc(sizeof(char) * mb_10);
		memset(a, 0, mb_10);
		sleep(1);
	}
 	
	
	return 0;
}