/*

Use MainLinkedLists2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of LinkedLists2 Lesson:

->Merging two Linked Lists
->Reversing a LinkedList
->Inserting at a specific index

*/
#include <stdio.h>
#include "FunctionHeadersLinkedLists2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};
struct passKeyNode *createnode(int num)
{
	struct passKeyNode *new_node = (struct passKeyNode*)malloc(sizeof(struct passKeyNode));
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

struct passKeyNode* strtoDLL(char *str)
{
	int len = 0;
	while (str[len] != '\0'){
		len++;
	}
	if (len == 0)
		return NULL;

	struct passKeyNode *head = createnode(str[len - 1] - '0');
	for (int i = len - 2; i >= 0; i--)
	{
		struct passKeyNode *temp = createnode(str[i] - '0');
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	return head;
}

int fact1(int n){
	int f = 1;
	for (int i = 2; i <= n; i++)
		f = f*i;
	return f;
}
int doorstoCross1(struct passKeyNode *passKeyHead)
{
	if (passKeyHead == NULL)
		return -1;
	int c = 1;
	struct passKeyNode *last = passKeyHead;
	struct passKeyNode *head = passKeyHead;
	struct passKeyNode *nn = passKeyHead;
	while (last->next != NULL){
		c++;
		last = last->next;
	}
	
//	printf("%d\n", c);
	int no_per = fact1(c);
	//printf("%d\n", no_per);

	for (int i = 1; i <= c; i++){
		nn = head->next;
		int count = 0, same = 1;
		while (nn != NULL)
		{
			if (nn->num < head->num)
				count++;
			else if (nn->num == head->num){
				printf(" num %d\n", nn->num);
				same++;
			}
			nn = nn->next;
		}
//		printf("%d %d\n", count,same);
		no_per = no_per - (count*(fact1(c - i) ));
		no_per = no_per / same;
	//	printf("no-per %d\n", no_per);
		head = head->next;
	}

	return no_per;
}
int main(){
	struct passKeyNode *passkey = strtoDLL("53124");
	int actualAns = doorstoCross1(passkey);
	printf("%d", actualAns);
	return 0;
}