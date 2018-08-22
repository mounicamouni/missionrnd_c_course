/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node* newnode(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node* ArrToBst(int *arr, int start, int end){
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;

	struct node *root = newnode(arr[mid]);

	root->left = ArrToBst(arr, start, mid - 1);

	root->right = ArrToBst(arr, mid + 1,end);
	
	return root;
}

struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL)
		return NULL;
	struct node *temp = ArrToBst(arr, 0, len);
	return temp;
}

