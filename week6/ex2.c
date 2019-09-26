#include <stdio.h>
#include <unistd.h>

#define STRING_SIZE 20

int main() {
	char string[STRING_SIZE] = "Hello world";
	char empty[STRING_SIZE] = "";
	int p[2], pid;

	if (pipe(p) < 0) {
		printf("Something bad happened");
		return 1;
	}

	write(p[1], string, STRING_SIZE);
	if (((pid = fork()) == 0)) {
		read(p[0], empty, STRING_SIZE);
		printf("Hello from child. String: %s\n", empty);
		
	} else {
		printf("Hello from parent. String: %s\n", empty);
	}
}