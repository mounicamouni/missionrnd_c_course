/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int * find_sequences(int *arr, int len){
	if (arr == NULL || len<0)
		return NULL;
	int diff, start, stop, c, k = 0;
	int *b = (int *)malloc(sizeof(int) * 6);
	for (int i = 0; i < len; i++){
		c = 0;
		diff = arr[i + 1] - arr[i];
		start = i;
		int j = i + 1;
		while (arr[j + 1] - arr[j] == diff){
			c++;
			j++;
		}
		if (c > 0){
			stop = j;
			b[k++] = start;
			b[k++] = stop;
		}
		i = j - 1;
	}
	float diff1, diff2;
	for (int i = 0; i < len; i++){
		c = 0;
		diff1 = (float)arr[i + 1] / arr[i];
		diff2 = (float)arr[i] / arr[i + 1];
		start = i;
		int j = i + 1;
		while (((float)arr[j + 1] / arr[j] == diff1) || ((float)arr[j + 1] / arr[j] == diff2) && (arr[j + 1]!=0 && arr[j]!=0)){
			c++;
			j++;
		}
		if (c > 0){
			stop = j;
			b[4] = start;
			b[5] = stop;
			break;
		}
	}

	return b;
}
