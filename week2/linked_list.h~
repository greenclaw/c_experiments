#include <stdio.h>

struct Node {
	int value;
	struct Node * next;
};

struct LinkedList {
	int size;
	struct Node * tail;
} list;

void print_list(struct LinkedList *l)
{	
	if ( l->size < 1) {
		printf("Stack is empty!");
		return;
	}
	int i;
	struct Node * current = l->tail;
	for(i = 0; i < l->size; i++) {
		printf("%d ", current->value);
		current = current->next;	
	}
}

void insert_node(int v,struct LinkedList *l)
{
	struct Node * node;
	node->value = v;
	node->next = l->tail;
	l->tail = node;
	l->size++;
}

int delete_node(struct LinkedList *l)
{
	if (l->size > 0) {
		l->tail = l->tail->next;
		l->size--;
		return 0;
	} else
		return 1;
}

