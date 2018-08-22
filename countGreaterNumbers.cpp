/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/


#include<stdio.h>
int isOlder(char *dob1, char *dob2) {
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
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || len < 0)
		return NULL;
	int c = 0;
	for (int i = 0; i < len; i++){
		int x = isOlder(Arr[i].date, date);
		if (x == 2)
			c++;
		else if (x == -1)
			return NULL;
	}
	return c;
}




