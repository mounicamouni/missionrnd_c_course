/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *last = head;
	int c = 1;
	while (last->next != NULL){
		last = last->next;
		c++;
	}
	if (c == 1)
		return head;
	//	printf(" c %d\n", c);
	//	printf(" last %d\n",last->num );

	struct node *temp, *l;
	l = last;
	for (int i = 0; i < c; i++){
		temp = head;
		while (temp->next != last)
		{
			temp = temp->next;
		}
		last->next = temp;
		last = temp;
	}
	last->next = head;
	head->next = NULL;

	return l;
}
