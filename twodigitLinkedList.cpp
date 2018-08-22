/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};

int convert_sll_2digit_to_int(struct twoDigitNode *head){
	int sum = 0, f = 100;
	
	//struct twoDigitNode *first = (struct twoDigitNode*)malloc(sizeof(struct twoDigitNode));
	struct twoDigitNode *first;
	first = head;

	while (first!= NULL){
		sum = sum*f +( (first->digit1) * 10 + (first->digit2) );
		first = first->next;
	}
	return sum;

}
