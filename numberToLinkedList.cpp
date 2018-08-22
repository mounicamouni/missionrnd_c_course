/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	if (N < 0)
		N = (-1)*N;
	if (N == 0){
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		newnode->num = 0;
		newnode->next =NULL;
		return newnode;
	}
	int rem,x=0;
	struct node *first = (struct node*)malloc(sizeof(struct node));
	while (N != 0){
		rem = N % 10;
		
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		if (x == 0){
			newnode->num = rem;
			newnode->next = NULL;
			first = newnode;
			x++;
		}
		else{
			newnode->num = rem;
			newnode->next = first;
			first = newnode;
		}

		N /= 10;
	}


	return first;
}