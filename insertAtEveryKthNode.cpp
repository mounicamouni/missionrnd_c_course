/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K < 1)
		return NULL;
	int c = 1;
	struct node *last = head;
	while (last->next != NULL){
		c++;
		last = last->next;
	}
//	printf("%d \n", c);
	//struct node *temp = NULL;
	struct node *first = head;
	int x = 0;
	//if (K > c)
		//return head;
	while (x + K <= c){
		for (int i = 0; i < K - 1; i++){
			first = first->next;
			//	x++;
		}
		struct node *xx = createNodeDummy(K);

		xx->next = (first->next);

		first->next = xx;
		first = xx->next;
		x = x + K;
	}

	return head;
}
