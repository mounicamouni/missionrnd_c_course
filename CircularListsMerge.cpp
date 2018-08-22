/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node **head1, struct node **head2){
	if (*head1 != NULL && *head2 != NULL)
	{
		struct node *ptr = NULL, *ptr2 = NULL, *temp = NULL;
		for (ptr = *head1; ptr->next != *head1; ptr = ptr->next);
		ptr->next = NULL;
		for (ptr = *head2; ptr->next != *head2; ptr = ptr->next);
		ptr->next = NULL;
		ptr = *head1;
		temp = ptr->next;
		for (ptr2 = *head2; ptr2 != NULL;)
		{
			if (ptr2->data < ptr->data)
			{
				struct node *tem = ptr2->next;
				ptr2->next = ptr;
				ptr = ptr2;
				*head1 = ptr;
				ptr2 = tem;
				temp = ptr->next;
			}
			else
			{
				if (temp == NULL)
				{
					break;
				}
				while (ptr2->data > temp->data && temp->next != NULL)
				{
					ptr = temp;
					temp = temp->next;
				}
				if (ptr2->data <= temp->data)
				{
					struct node *tem = ptr2->next;
					ptr2->next = temp;
					ptr->next = ptr2;
					ptr = ptr->next;
					ptr2 = tem;
				}
				else if (temp->next == NULL)
				{
					break;
				}
			}

		}
		if (temp == NULL)
		{
			ptr->next = ptr2;
		}
		else if (temp->next == NULL)
		{
			temp->next = ptr2;
		}
		int count = 0;
		for (ptr = *head1; ptr->next != NULL; ptr = ptr->next)
		{
			count++;
		}
		count++;
		ptr->next = *head1;
		return count;
	}
	return -1;
}