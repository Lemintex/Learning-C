#include "linkedlist.h"
#include <stdio.h>

int main() {

	linkedlist_t* list = createPopulatedLinkedList();
	printLinkedList(list);
	deleteLinkedList(list);
	return 0;
}
