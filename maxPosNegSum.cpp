
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input, int length)
{
	if (length <= 0)
		return 0;
	int maxp = 0, maxn = 0, l = 0, c1 = 0, c2 = 0;

	for (int i = 0; i < length; i++){
		if (input[i]>0)
			c1++;
		else if (input[i] < 0)
			c2++;

		if (input[i]>0 && input[i] > maxp){
			maxp = input[i];

		}
		else if (input[i] < 0 && l == 0){
			maxn = input[i];
			l = 1;

		}
		else if (input[i]<0 && input[i] > maxn)
		{
			maxn = input[i];

		}
	}
	if (c1 == length || c2 == length)
		return 0;
	return maxp + maxn;
	return 0;
}