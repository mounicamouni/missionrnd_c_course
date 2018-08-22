/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorderhelp(struct node *root, int *arr,int *ind){
	if (root != NULL){
		inorderhelp(root->left, arr,ind);
		arr[*ind] = root->data;
		*ind=*ind+1;
		inorderhelp(root->right, arr,ind);
	}
}
void preorderhelp(struct node *root, int *arr, int *ind){
	if (root != NULL){
		arr[*ind] = root->data;
		*ind = *ind + 1;
		preorderhelp(root->left, arr,ind);
		preorderhelp(root->right, arr,ind);
	}
}
void postorderhelp(struct node *root, int *arr, int *ind){
	if (root != NULL){
		postorderhelp(root->left, arr,ind);
		postorderhelp(root->right, arr,ind);
		arr[*ind] = root->data;
		*ind = *ind + 1;
	}
}

void inorder(struct node *root, int *arr){
	if (root != NULL&&arr != NULL){
		int ind = 0;
		inorderhelp(root, arr, &ind);
	}
}
void preorder(struct node *root, int *arr){
	if (root != NULL&&arr != NULL){
		int ind = 0;
		preorderhelp(root, arr, &ind);
	}
}
void postorder(struct node *root, int *arr){
	if (root != NULL&&arr != NULL){
		int ind = 0;
		postorderhelp(root, arr, &ind);
	}
}

