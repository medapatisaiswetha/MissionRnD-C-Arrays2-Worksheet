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
#include <iostream>
#include <malloc.h>

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	if (Arr == 0 || len <= 0)
		return NULL;
	else
	{
		int i = 0, k = 0, d = 0, m = 0, y = 0, c = 0, res = 0, m1 = 0, d1 = 0, y1 = 0;
		while (date[i] != '\0')
		{
			if (date[i] != '-')
			{
				if (date[i] >= 48 && date[i] <= 57)
				{
					if (c == 0)
					{
						d = (d * 10) + (date[i] - '0');
					}
					if (c == 1)
					{
						m = (m * 10) + (date[i] - '0');
					}
					if (c == 2)
					{
						y = (y * 10) + (date[i] - '0');
					}
				}
			}
			else if (date[i] == '-')
			{
				c++;
			}
			i++;
		}
		i = 0, c = 0;
		while (k < len)
		{
			while (Arr[k].date[i] != '\0')
			{
				if (Arr[k].date[i] != '-')
				{
					if (Arr[k].date[i] >= 48 && Arr[k].date[i] <= 57)
					{
						if (c == 0)
						{
							d1 = (d1 * 10) + (Arr[k].date[i] - '0');
						}
						if (c == 1)
						{
							m1 = (m1 * 10) + (Arr[k].date[i] - '0');
						}
						if (c == 2)
						{
							y1 = (y1 * 10) + (Arr[k].date[i] - '0');
						}
					}
				}
				else if (Arr[k].date[i] == '-')
				{
					c++;
				}
				i++;
			}
			if (Arr[k].date[i] == '\0')
			{
				if (y1 >y)
				{
					res++;
				}
			}
			k++;
			i = 0;
			c = 0;
			d1 = 0;
			m1 = 0;
			y1 = 0;
		}
		return res;
	}
}
