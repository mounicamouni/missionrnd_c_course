/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;      
	int data;
	struct node *right;
};

int get_height1(struct node *root){
	if (root == NULL)
		return 0;
	else{
		int ldepth = get_height1(root->left);
		int rdepth = get_height1(root->right);

		if (ldepth>rdepth)
			return (ldepth + 1);
		else
			return (rdepth + 1);
	}
}

void getrighttoleft(struct node *root, int *arr, int level,int *index){
	if (root == NULL)
		return;
	if (level == 1){
		arr[*index] = root->data;
		*index += 1;
	}
	else{
		getrighttoleft(root->right, arr, level - 1, index);
		getrighttoleft(root->left, arr, level - 1, index);
	}
		
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int *arr = (int *)malloc(sizeof(int) * 100);
	int height = get_height1(root);
	int ind = 0;
	for (int i = 1; i <= height; i++)
		getrighttoleft(root, arr,i,&ind);
    return arr;
}
