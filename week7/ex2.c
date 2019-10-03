#include <stdio.h>
#include <stdlib.h>


int main() {
	int N;
	printf("Enter N >> ");
	scanf("%d", &N);

	int *a = malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i) {
		a[i] = i;
	}

	printf("Array { ");
	for (int i = 0; i < N; ++i) {
		printf("%d ", a[i]);
	}
	printf("}\n"); 
	free(a);
	
	return 0;
}