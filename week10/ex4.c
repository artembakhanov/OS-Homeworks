#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define MAX_FILES 10000

ino_t inodes[MAX_FILES] = {-1};
int find_inode(ino_t inode) {
	int i;
	for (i = 0; i < MAX_FILES && inode != 0; ++i) {
		if (inodes[i] == inode) return 0;
	}
	inodes[i] = inode;
	return 1;
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
			sprintf(command, "find . -inum %d", dp->d_ino);
			system(command);
		}
	
	}

	return 0;
}