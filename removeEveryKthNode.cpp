/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (K <= 1 || head == NULL)
		return NULL;
	int c = 1;
	struct node *last = head;
	while (last->next != NULL){
		c++;
		last = last->next;
	}
	//printf("%d \n", c);
	struct node *temp = NULL;
	struct node *first = head;
	int x = 0;
	while (x + K <= c){
		for (int i = 0; i < K - 2; i++)
			first = first->next;
	//	printf("firstdata %d \n", first->num);
		temp = (first->next)->next;

		first->next = temp;
		first = temp;
		x = x + K;
	}
	return head;
}