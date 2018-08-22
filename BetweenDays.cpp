/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	int f1 = 10, f2 = 10, f3 = 1000;
	int c = 0;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < 8; i++){
		if (i >= 0 && i < 2){
			d1 = d1 + date1head->data*f1;
			d2 = d2 + date2head->data*f1;
			f1 /= 10;
		}
		else if (i >= 2 && i < 4){
			m1 = m1 + date1head->data*f2;
			m2 = m2 + date2head->data*f2;
			f2 /= 10;
		}
		else{
			y1 = y1 + date1head->data*f3;
			y2 = y2 + date2head->data*f3;
			f3 /= 10;
		}
		date1head = date1head->next;
		date2head = date2head->next;
	}
	//	printf("%d %d %d ", d1, m1, y1);
	//printf("%d %d %d ", d2, m2, y2);

	long int n1 = y1 * 365 + d1;
	for (int i = 0; i < m1 - 1; i++)
		n1 += monthDays[i];

	if (m1 <= 2)
		y1--;
	n1 = n1 + (y1 / 4 - y1 / 100 + y1 / 400);

	long int n2 = y2 * 365 + d2;
	for (int i = 0; i < m2 - 1; i++)
		n2 += monthDays[i];

	
	if (m2 <= 2)
		y2--;
	n2 = n2 + (y2 / 4 - y2 / 100 + y2 / 400);

	int res = n2 - n1 - 1;
	//printf("\n%d ", res);
	if (res < 0)
		res = res*(-1) - 2;
	if (n1 == n2)
		res = 0;
	return res;
}