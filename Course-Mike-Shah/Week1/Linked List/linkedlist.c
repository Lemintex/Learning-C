#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
linkedlist_t* createLinkedList() {
	linkedlist_t* list = (linkedlist_t*)malloc(sizeof(linkedlist_t));

	list->head = NULL;
	return list;
}

linkedlist_t* createPopulatedLinkedList() {
	linkedlist_t* list = createLinkedList();
	appendLinkedList(list, 1);
	appendLinkedList(list, 2);
	appendLinkedList(list, 3);
	return list;
}

void printLinkedList(linkedlist_t* list) {
	node_t* node = list->head;
	while(node != NULL) {
		printf("Value = %i\n", node->data);
		node = node->next;
	}
}

void deleteLinkedList(linkedlist_t* list) {
	node_t* current = list->head;
	if (current == NULL) {
		free(list);
		return;
	}
		node_t* next = current->next;
	while(current != NULL) {
		free(current);
		current = next;
		if(current != NULL) {
			next = current->next;
		}
	}
	free(list);
}

void appendLinkedList(linkedlist_t* list , int data) {
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = data;
	if (list->head == NULL) {
		list->head = newNode;
		return;
	}
	node_t* node = list->head;
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = newNode;
}
