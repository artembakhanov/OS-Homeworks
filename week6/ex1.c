#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#define STRING_SIZE 20

int main() {
	char string[STRING_SIZE] = "Hello world!";
	char empty[STRING_SIZE];

	int p[2];

	if (pipe(p) < 0) {
		printf("Something bad happened.");
		return 1;
	}

	write(p[1], string, STRING_SIZE);
	read(p[0], empty, STRING_SIZE);
	printf("%s", empty);

	return 0;
}