/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){
	
}

/*
This is the actual function. You are supposed to change only the links.
*/

struct node *add(struct node *ptr, struct node *p)
{
	struct node* tem = p;
	if (p == NULL)
	{
		p = ptr;
		p->next = NULL;
		tem = p;
	}
	else
	{
		tem = p;
		for (; p->next != NULL; p = p->next);
		p->next = ptr;
		p = p->next;
		p->next = NULL;
	}
	return tem;
}
void sll_012_sort(struct node **head)
{
	struct node *ptr, *p;
	struct node *ptr0 = NULL, *ptr1 = NULL, *ptr2 = NULL;
	for (ptr = *head; ptr != NULL;)
	{
		struct node *temp = ptr->next;
		if (ptr->data == 0)
		{
			ptr0 = add(ptr, ptr0);
		}
		else if (ptr->data == 1)
		{
			ptr1 = add(ptr, ptr1);
		}
		else if (ptr->data == 2)
		{
			ptr2 = add(ptr, ptr2);
		}
		ptr = temp;
	}
	*head = ptr0;
	if (*head == NULL)
	{
		*head = ptr1;
	}
	else
	{
		p = *head;
		for (p = *head; p->next != NULL; p = p->next);
		p->next = ptr1;
	}
	if (*head == NULL)
	{
		*head = ptr2;
	}
	else
	{
		p = *head;
		for (p = *head; p->next != NULL; p = p->next);
		p->next = ptr2;
	}
}