/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	struct node *last = head;
	struct node *first = head;
	int c = 1;
	while (last->next != NULL){
		last = last->next;
		c++;
	}
//	printf("%d", c);
	int x, f, res;
	if (c % 2 == 1){
		x = c / 2 + 1;
		f = 0;
		while (first != NULL)
		{

			f++;
			if (f == x){
				res = first->num;
				break;
			}
			first = first->next;
		}
		return res;
	}

	x = c / 2;
	f = 0;
	res = 0;
	first = head;
	while (first != NULL)
	{
		f++;
		if (f == x || f == x + 1){
			res = res + first->num;
		}
		if (f == x + 1)
			break;

		first = first->next;
	}

	return res / 2;
}
