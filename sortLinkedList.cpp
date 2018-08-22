/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	int c = 1;
	struct node *last = head;
	while (last->next != NULL){
		c++;
		last = last->next;
	}
	struct node *first,*second;
	for (int i = 0; i < c-1; i++){
		first = head;
		second = first->next;
		for (int j = 0; j < c - i-1; j++){
			if (second->num < first->num){
				int temp = first->num;
				first->num = second->num;
				second->num = temp;
			}
			first = first->next;
			second = second->next;
		}
	}


	return head;
}