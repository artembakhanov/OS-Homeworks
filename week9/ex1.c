// This program simulates aging algorithm. The first parameter is the number of page frames. 
// The second one is the name of the input file. 
// Example: './ex1 10 input.txt'
// The clock tick happens as soon as a page is referenced.

//./ex1 10 input.txt
//---------------------------------
//| hits          | 9             |
//| misses        | 992           |
//| hit/miss ratio| 0.009073      |
//---------------------------------

//./ex1 50 input.txt
//---------------------------------
//| hits          | 51            |
//| misses        | 950           |
//| hit/miss ratio| 0.053684      |
//---------------------------------

//./ex1 100 input.txt
//---------------------------------
//| hits          | 94            |
//| misses        | 907           |
//| hit/miss ratio| 0.103638      |
//---------------------------------



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define FALSE -1

// page frame structure
typedef struct page_s {
	int pframe;
	int age;
} page_t;

int npages = 10;

int find_page(int, page_t[]);
int find_most_aged_frame(int, page_t[]);
void age(int, page_t[]);


int main(int argc, char *argv[]) {
	int hits = 0, misses = 0;
	char *fname = "input.txt";
	
	if (argc < 3 || sscanf(argv[1], "%d", &npages) != 1) {
		printf("\033[1;31mFirst argument is the number of pages.\n"
			   "The second one is the name of the input file.\n"
		       "\033[1;34mExample: './ex1 10 input.txt'\033[0m");
		return -1;
	}

	fname = argv[2];

	page_t pages[npages];
	for (int i = 0; i < npages; ++i) {
		pages[i].pframe = -1;
		pages[i].age = 0;
	}

	FILE *input = fopen(fname, "r");
	int rframe;
	while (!feof(input)) {
		if (!fscanf(input, "%d", &rframe)) {
			printf("\033[1;31mThe format of the file is incorrect. File must consist of numbers divided by whitespaces.\n\033[0m");
			return -1;
		}
		int vpage;
		if (vpage = find_page(rframe, pages) == FALSE) {
			find_most_aged_frame(rframe, pages);
			misses++;			
		} else
			hits++;
		age(rframe, pages);
	}

	printf("---------------------------------\n");
	printf("| hits\t\t| %d \t\t|\n", hits);
	printf("| misses\t| %d \t\t|\n", misses);
	printf("| hit/miss ratio| %f \t|\n", hits / (float) misses);
	printf("---------------------------------\n");

	return 0;
}

// find the most aged page frame for replacing
int find_most_aged_frame(int rframe, page_t pages[]) {
	int min = INT_MAX;
	int imin = 0;
	for (int i = 0; i < npages; ++i) {
		if (pages[i].pframe == FALSE) {
			imin = i;
			break;
		} 

		if (pages[i].age < min) {
			min = pages[i].age;
			imin = i;
		}
	}

	pages[imin].pframe = rframe;
	pages[imin].age = 0;
	
	return imin;
}

// perform ageing
void age(int rframe, page_t pages[]) {
	for (int i = 0; i < npages; ++i) {
		pages[i].age >>= 1;
		if (i == rframe) {
			pages[i].age += INT_MAX - INT_MAX >> 1; // set the most significant bit to 1
		}
	}
}

// find page frame
int find_page(int page, page_t pages[]) {
	for (int i = 0; i < npages; ++i) {
		if (pages[i].pframe == page) return i;
	}
	return FALSE;
}
