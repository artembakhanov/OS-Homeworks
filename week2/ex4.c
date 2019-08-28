#include <stdio.h>

int swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a, b;
	scanf("%i %i",&a, &b);
	
	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
		
	return 0;
}