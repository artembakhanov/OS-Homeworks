#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 500

int main() {
	char *input = malloc(MAX_SIZE);
	scanf("%[^\t\n]s", input);
	int len = strlen(input);

	for (int i = len - 1; i >= 0; --i) {
		printf("%c", input[i]);
	}
	
	return 0;
}