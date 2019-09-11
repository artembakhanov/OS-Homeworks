#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	printf("Welcome to simple shell, developed by Artem Bahanov. Type 'q' to exit.\nSequoia-console> ");

	char command[20];
	fgets(command, 20, stdin);
	while (strcmp(command, "q\n")) {
		printf("Sequoia-console> ");
		if (!fork()) {
			system(command);
			return 0;
		}
		fgets(command, 20, stdin);
	}
	
	return 0;
}