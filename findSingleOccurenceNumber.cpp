/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
void merge(int *a,int l,int mid,int r){

	int x = mid -l + 1;
	int y = r - mid;
	int *b=(int*)malloc(sizeof(int)*x);
	int *c = (int*)malloc(sizeof(int)*y);
	for (int i = 0; i < x; i++){
		b[i] = a[i + l];
	}
	for (int i = 0; i < y; i++){
		c[i] = a[i + mid+1];
	}

	int i = 0, j = 0;
	while (i < x&&j < y){
		if (b[i]<c[j])
			a[l++] = b[i++];
		else
			a[l++] = c[j++];
	}
	
	while (i<x)
		a[l++] = b[i++];

	while (j<y)
		a[l++] = c[j++];

}
void mergesortArr(int *a,int l,int r){
	if (l < r){
		int mid = l + (r - l) / 2;
		mergesortArr(a, l, mid);
		mergesortArr(a, mid+1,r);

		merge(a, l, mid, r);
	}
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len < 0)
		return -1;
	mergesortArr(A,0,len-1);
	for (int i = 0; i < len;){
		if (A[i] == A[i + 1] && A[i] == A[i + 2]){
			i = i + 3;
		}
		else return A[i];
	}
	return -1;
}