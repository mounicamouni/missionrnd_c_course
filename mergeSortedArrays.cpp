/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int Older(char *dob1, char *dob2) {
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
		return -1;
	int x1, x2, y1, y2, z1 = 0, z2 = 0;
	int h = 1000;
	for (int i = 6; i < 10; i++)
	{
		z1 = z1 + (dob1[i] - 48) * h;
		z2 = z2 + (dob2[i] - 48) * h;
		h = h / 10;
	}

	x1 = (dob1[0] - 48) * 10 + (dob1[1] - 48);
	x2 = (dob2[0] - 48) * 10 + (dob2[1] - 48);

	if (x1<1 || x1>31 || x2<1 || x2>31)
		return -1;
	y1 = (dob1[3] - 48) * 10 + (dob1[4] - 48);
	y2 = (dob2[3] - 48) * 10 + (dob2[4] - 48);
	if (y1<1 || y1>12 || y2<1 || y2>12)
		return -1;
	if (z1 % 4 != 0 && y1 == 2 && x1>28)
		return -1;
	if (z2 % 4 != 0 && y2 == 2 && x2>28)
		return -1;

	if (z1 > z2)
		return 2;
	else if (z2 > z1)
		return 1;

	if (y1 > y2)
		return 2;
	else if (y2 > y1)
		return 1;

	if (x1 > x2)
		return 2;
	else if (x2 > x1)
		return 1;
	return 0;

}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;
	struct transaction *rs;
	rs = (struct transaction*)malloc(sizeof(struct transaction)*(ALen+BLen));
	int i = 0, j = 0, k = 0;
	
	while (i < ALen&&j < BLen){
		if (Older(A[i].date, B[j].date) == 1)
			rs[k++] = A[i++];
		else
			rs[k++] = B[j++];
	}

	while (i<ALen)
		rs[k++] = A[i++];

	while (j<BLen)
		rs[k++] = B[j++];

	return rs;
}