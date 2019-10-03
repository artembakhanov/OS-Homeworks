#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#define SIZE 8


void *mrealloc(void *ptr, size_t old_size, size_t new_size) {
	void *newptr; // new pointer

	if (ptr == NULL) newptr = malloc(new_size);
	else if (new_size != 0) {
		newptr = malloc(new_size);
		memcpy(newptr, ptr, old_size > new_size ? new_size : old_size);
	}

	free(ptr);
	return newptr;
}

void print_arr(int *a, int size, char *arr_name) {
		printf("Arr %s { ", arr_name);
		for (int i = 0; i < size; ++i) {
 			printf("%d ", a[i]);
		}
		printf("}\n");
}

int main() {
	int *a = malloc(sizeof(int) * SIZE);
	for (int i = 0; i < SIZE; ++i) {
		a[i] = SIZE  - i;
	}	
	print_arr(a, SIZE, "Old");	
	a = mrealloc(a, sizeof(int) * SIZE, 16 * sizeof(int));
	print_arr(a, 16, "New");
	free(a);
	return 0;
}