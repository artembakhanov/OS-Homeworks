#include <stdio.h>
#include <unistd.h>

int main() {
	int n = 13;
	int child = fork();
	if (child == 0) 
		printf("Hello from child [%d - %d]\n", getpid(), n);
	else
		printf("Hello from parent [%d - %d]\n", getpid(), n);

	return 0;
}

/* Results. As we can see, the system creates several processes and their ID are different.
Hello from parent [3200 - 13]
Hello from child [3201 - 13]
Hello from parent [3202 - 13]
Hello from child [3203 - 13]
Hello from parent [3204 - 13]
Hello from child [3205 - 13]
Hello from parent [3206 - 13]
Hello from child [3207 - 13]
Hello from parent [3208 - 13]
Hello from child [3209 - 13]
Hello from parent [3210 - 13]
Hello from child [3211 - 13]
Hello from parent [3212 - 13]
Hello from child [3213 - 13]
Hello from parent [3214 - 13]
Hello from child [3215 - 13]
Hello from parent [3216 - 13]
Hello from child [3217 - 13]
Hello from parent [3218 - 13]
Hello from child [3219 - 13]
*/