#include <stdio.h>
#include <stdlib.h>

typedef struct node {
 	int value;
 	struct node *next;
} node_t;

typedef struct LL {
	struct node *head;
	int size;
} LinkedList;

// create an empty linked list
LinkedList* create_empty() {
	LinkedList* list = malloc(sizeof(LinkedList));
	list->size = 0;
	list->head = NULL;
}

// insert element with a given value
void insert_last(LinkedList *l, int value) {
	l->size++;
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;

	if (l->head == NULL) l->head = new_node;
	else { 
		node_t *now = l->head;
		while (now->next != NULL) now = now->next;

		now->next = new_node;
	}
}

// delete the first element from list
void delete_first(LinkedList *l) {
	if (l->head != NULL) {
		l->size--;
		node_t *new_head = l->head->next;
		free(l->head);
		l->head = new_head;
	}
}

// delete the last element
void delete_last(LinkedList *l) {
	if (l->head == NULL) return;
	l->size--;
	if (l->head->next == NULL){
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

// print elements of the list
void print_list(LinkedList *l) {
	node_t *now = l->head;
	printf("LinkedList [%d]{ ", l->size);
	while(now != NULL) {
		printf("%d ", now->value);
		now = now->next;
	}
	printf("}\n");
}

// remove element that is in index position
void delete_by_index(LinkedList *l, int index) {
	if (l->size <= index) return;
	else if (index == 0) return delete_first(l);
	else if (index == l->size - 1) return delete_last(l);

	node_t *now = l->head;
	for (int i = 0; i < index - 1; ++i) {
		now = now->next;
	}

	node_t *new_next = now->next->next;
	free(now->next);
	now->next = new_next;	
	l->size--;
}

int find_value_index(LinkedList *l, int value) {
	node_t *now = l->head;
	for (int i = 0; i < l->size; i++) {
		if (now->value == value) {
			return i;
		} else {
			now = now->next;
		}
	}

	return -1;
}

void delete_with_value(LinkedList *l, int value) {
	int index = find_value_index(l, value);
	if (index == -1) return;
	else delete_by_index(l, index);
}


/* test linked list */
int main() {
	LinkedList *l = create_empty();
	insert_last(l, 2);
	insert_last(l, 5);
	insert_last(l, 1);
	insert_last(l, 9);
	print_list(l);
	delete_last(l);
	delete_last(l);
	print_list(l);
	delete_with_value(l, 2);
	print_list(l);
	

	return 0;
}