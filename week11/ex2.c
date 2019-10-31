#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("H");
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1); // this works!!!
	
	return 0;
}