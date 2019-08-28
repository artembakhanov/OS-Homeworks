#include <stdio.h>

/*
	prints a pyramid 
 	 * 
    ***
   *****
*/
void pyramid(int n) {
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
}

/* 
	prints a square
		***
		***
		***
*/
void square(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("*");
		}
		printf("\n");
	}
}

/* 
	prints a square
		***
		***
		***
*/
void semipyramid(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}
}


/*
	prints a triangle
	*
	**
	***
	***
	**
	*
*/
void triangle(int n) {
	for (int i = 0; i < (n + 1) / 2; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = n / 2; i >= 1; --i) {
		for (int j = 0; j <= i; ++j) {
			printf("*");
		}
		printf("\n");
	}
}


int main(int argc, char *argv[]) {
	int t, n;
	int err = sscanf(argv[1], "%d",&t) + sscanf(argv[2], "%d",&n);;
	
	if (err != 2) {
		printf("Error, please enter two  numbers (type of figure[1-4] and number of lines)");
		return 1;
	}

	switch(t) {

		case 1:
			pyramid(n);
			break;
		case 2:
			square(n);
			break;
		case 3:
			semipyramid(n);
			break;
		case 4:
			triangle(n);
			break;
		default:
			printf("Error, please enter two  numbers (type of figure[1-4] and number of lines)");
	}
	
	return 0;
}