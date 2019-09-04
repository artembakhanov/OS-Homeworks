#include <stdio.h>

void bubble_sort(int a[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; j++) {
			// swap here
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main() {
	int a[] = {4,1, 3, 10};
	bubble_sort(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}