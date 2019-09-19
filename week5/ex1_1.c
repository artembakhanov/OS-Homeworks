#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct thread_arg {
	int number;
	char *message;
}thargs;

void *thread(void *arg) {
	thargs *args = (thargs*)arg;
	printf("[%d] Thread %d is created.\n", args->number, args->number);
	printf("[%d] The given message: \"%s\"\n", args->number, args->message);
	printf("[%d] Exit.\n", args->number);
	free(args);

	return NULL;
}

int main() {
	
	for (int i = 0; i < 10; ++i) {
		pthread_t tid;
		thargs *args = malloc(sizeof(thargs));
		args->message = "Hello world!";
		args->number = i;
		if (pthread_create(&tid, NULL, thread, args) != 0) 
			printf("There was an error while creating thread%d\n", i); 
	}

	return 0;
}

/*
One of the outputs:

[0] Thread 0 is created.
[0] The given message: "Hello world!"
[0] Exit.
[1] Thread 1 is created.
[1] The given message: "Hello world!"
[1] Exit.
[3] Thread 3 is created.
[3] The given message: "Hello world!"
[3] Exit.
[4] Thread 4 is created.
[4] The given message: "Hello world!"
[5] Thread 5 is created.
[7] Thread 7 is created.
[7] The given message: "Hello world!"
[7] Exit.
[6] Thread 6 is created.
[8] Thread 8 is created.
[8] The given message: "Hello world!"
[8] Exit.
[6] The given message: "Hello world!"
[6] Exit.
[9] Thread 9 is created.

This is can be explained very easily. The scheduler decides to switch from one thread to another fairly. That is why the messages are not ordered.
It is worth mentioning that thread 9 was created but the it did not have time to print message and even exit since the main thread was finished before (and the process as well).
*/