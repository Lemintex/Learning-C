#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
	int data;
	struct node* next;
}node_t;

typedef struct linkedlist {
	node_t* head;
}linkedlist_t;

linkedlist_t* createLinkedList();

linkedlist_t* createPopulatedLinkedList();

void printLinkedList(linkedlist_t* list);

void deleteLinkedList(linkedlist_t* list);

void appendLinkedList(linkedlist_t* list, int data);

#endif
