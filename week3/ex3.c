#include <stdio.h>
#include <stdlib.h>

typedef struct node {
 	int value;
 	struct node *next;
} node_t;

typedef struct LL {
	struct node *head;
} LinkedList;

void insert_last(LinkedList *l, int value) {
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;

	if (l->head == NULL) l->head = new_node;
	else { 
		node_t *now = l->head;
		while (now->next != NULL) now = now->next;

		now->next = new_node;
	}
}

void print_list(LinkedList *l) {
	node_t *now = l->head;
	printf("LinkedList { ");
	while(now != NULL) {
		printf("%d ", now->value);
		now = now->next;
	}
	printf("}");
}

void delete_last(LinkedList *l) {
	if (l->head == NULL) return;
	else if (l->head->next == NULL){
		free(l->head);
		l->head = NULL;
	}
	else {
		node_t *now= l->head;
		while (now->next->next != NULL) {
			now = now->next;
		}
		free(now->next);
		now->next = NULL;
	}
}


/* test linked list */
int main() {
	LinkedList *l = malloc(sizeof(LinkedList));
	insert_last(l, 2);
	insert_last(l, 5);
	insert_last(l, 1);
	insert_last(l, 9);
	delete_last(l);
	delete_last(l);
	print_list(l);
	

	return 0;
}