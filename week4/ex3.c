#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	printf("Welcome to simple shell, developed by Artem Bahanov. Type 'q' to exit.\nSequoia-console> ");

	char command[20];
	fgets(command, 20, stdin);
	while (strcmp(command, "q\n")) {
		printf("Sequoia-console> ");
		system(command);
		fgets(command, 20, stdin);
	}
	
	return 0;
}

/* This is how it works with simple commands on my system (arch).

artembakhanov@artem-pc ~/week4> ./ex3
Welcome to simple shell, developed by Artem Bahanov.
Sequoia-console> pwd
/home/artembakhanov/week4
Sequoia-console> ls    
ex1  ex1.c  ex1.sh  ex2  ex2.c  ex3  ex3.c  ex4.c
Sequoia-console> echo hello
hello
Sequoia-console> mkdir
mkdir: missing operand
Try 'mkdir --help' for more information.
Sequoia-console> mkdir sos
Sequoia-console> ls
ex1  ex1.c  ex1.sh  ex2  ex2.c  ex3  ex3.c  ex4.c  sos
Sequoia-console> rm -r sos
Sequoia-console> ls
ex1  ex1.c  ex1.sh  ex2  ex2.c  ex3  ex3.c  ex4.c
*/