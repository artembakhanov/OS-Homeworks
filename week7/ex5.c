#include <stdio.h>
#include <stdlib.h>

int main() {
	char **s = malloc(sizeof(char *)); // we should allocate memory here
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n", *s); // we should pass char * instead of char **
	s[0] = foo;
	printf("s is %s\n", s[0]);
	
	return (0); // ?????
}