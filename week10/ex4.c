#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define MAX_FILES 10000

ino_t inodes[MAX_FILES] = {0};
int find_inode(ino_t inode) {
	int i;
	int c = 0;
	for (i = 0; i < MAX_FILES && inodes[i] != 0; ++i) {
		if (inodes[i] == inode) c++;
		if (c > 1) {
			return 0;
		}
	}
	inodes[i] = inode;
	return c == 1;
}
int main() {
	DIR *dirp = opendir("tmp"); // get dir tmp
	if (dirp == NULL) {
		printf("Error while opening dir tmp");
		return -1;
	}

	struct dirent *dp;
	while ((dp = readdir(dirp)) != NULL) {
		if (find_inode(dp->d_ino)) {
			char command[256];
			printf("inode %d\n", dp->d_ino);
			fflush(stdout);
			sprintf(command, "find . -inum %d", dp->d_ino);
			system(command);
			printf("\n");
			fflush(stdout);
		}
	
	}

	return 0;
}