#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>


int main(void) {
	const char file_name[] = "ex1.txt";
	const char new_string[] = "This is a nice day";

	int file = open(file_name, O_RDWR);
	ftruncate(file, strlen(new_string));
	
	char *addr = mmap(NULL, strlen(new_string), PROT_WRITE, MAP_SHARED, file, 0);
	strcpy(addr, new_string);

	munmap(addr, strlen(new_string));
	close(file);

	return 0;
}