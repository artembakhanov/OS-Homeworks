#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

int main(void) {
	const char file_name1[] = "ex1.txt";
	const char file_name2[] = "ex1.memcpy.txt";

	struct stat file_stat1, file_stat2;
	int file1 = open(file_name1, O_RDWR);
	int file2 = open(file_name2, O_RDWR | O_CREAT, 0666);
	fstat(file1, &file_stat1);
	fstat(file2, &file_stat2);
	ftruncate(file2, file_stat1.st_size);

	char *addr1 = mmap(NULL, file_stat1.st_size, PROT_READ, MAP_SHARED, file1, 0); // just reading from here
	char *addr2 = mmap(NULL, file_stat1.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, file2, 0); // only writing or creating here
	memcpy(addr2, addr1, file_stat1.st_size);

	munmap(addr1, file_stat1.st_size);
	munmap(addr2, file_stat1.st_size);
	
	close(file1);
	close(file2);
	
	return 0;	
}