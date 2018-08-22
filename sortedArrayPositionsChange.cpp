/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int in1 = 0, in2 = 0, f = 0;
	if (Arr == NULL || len < 0)
		return NULL;
	for (int i = 1; i < len; i++){
		if (Arr[i] < Arr[i - 1] && f == 0){
			in1 = i - 1;
			f = 1;
		}
		else if (Arr[i] < Arr[i - 1] && f == 1){
			in2 = i;
			break;
		}
	}

	int temp = Arr[in1];
	Arr[in1] = Arr[in2];
	Arr[in2] = temp;
	return NULL;
}