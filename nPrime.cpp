
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<malloc.h>
int* nPrime(int N)
{
	if (N < 2)
		return NULL;
	int *n,x=0;
	n = (int*)malloc(sizeof(int)*N);
	for (int i = 2; i <=N; i++){
		int f = 0;
		for (int j = 2; j < i; j++){
			if (i%j == 0)
			{
				f = 1;
				break;
			}
		}
		if (f == 0)
			n[x++] = i;

	}	
	return n;
}