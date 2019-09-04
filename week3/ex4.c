#include <stdio.h>
#include <stdlib.h>

/*
 * Swap two elements with indices i1 and i2 in array a 
 */
void swap(int a[], int i1, int i2) {
	int temp = a[i1];
	a[i1] = a[i2];
	a[i2] = temp;
}

/*
 * Divide array into 2 parts and pivot that is on position min_pos
 */
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int min_pos = low;
	for (int i = low; i < high; ++i) {
		if (a[i] <= pivot) {
			swap(a, i, min_pos);
			min_pos++;
		}
	}

	swap(a, min_pos, high);

	return min_pos;
}

/*
 * Recursive quick sort
 */
void quick_sort_t(int a[], int low, int high) {
	if (low < high) {
		int p = partition(a, low, high);
		quick_sort_t(a, low, p - 1);
		quick_sort_t(a, p + 1, high);
	}
}

/* 
 * Quick sort for clients
 */
void quick_sort(int a[], int len) {
	quick_sort_t(a, 0, len - 1);
}


int main() {
	int a[] = {3, 2, 11, 9, 1, 6};
	quick_sort(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}