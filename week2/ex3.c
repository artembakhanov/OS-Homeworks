#include <stdio.h>


int main(int argc, char *argv[]) {
	int n;
	int err = sscanf(argv[1], "%d", &n);
	if (err == 0) {
		printf("Error, please enter a number");
		return 1;
	}
	
	int max = n * 2 - 1; // the maximum number of elements (the lowest level)
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			printf(" "); // here we print n - i - 1 whitespaces
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			printf("*"); // stars
		}
		printf("\n"); // next level
	}

	return 0;
	
}