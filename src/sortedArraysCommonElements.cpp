/*
OVERVIEW: You are given 2 bank statements that are ordered by date.
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL)
		return NULL;
	else
	{
		struct transaction *res = NULL;
		int k = 0, i = 0, c = 0, r = 0, m1 = 0, m2 = 0, d1 = 0, d2 = 0, y1 = 0, y2 = 0, j = 0, count = 0;
		while (j < BLen)
		{
			while (B[j].date[i] != '\0')
			{
				if (B[j].date[i] != '-')
				{
					if (B[j].date[i] >= 48 && B[j].date[i] <= 57)
					{
						if (c == 0)
						{
							d1 = (d1 * 10) + (B[j].date[i] - '0');
						}
						if (c == 1)
						{
							m1 = (m1 * 10) + (B[j].date[i] - '0');
						}
						if (c == 2)
						{
							y1 = (y1 * 10) + (B[j].date[i] - '0');
						}
					}
				}
				else if (B[j].date[i] == '-')
				{
					c++;
				}
				i++;
			}

			if (B[j].date[i] == '\0')
			{
				i = 0;
				c = 0;
				while (k < ALen)
				{
					while (A[k].date[i] != '\0')
					{
						if (A[k].date[i] != '-')
						{
							if (A[k].date[i] >= 48 && A[k].date[i] <= 57)
							{

								if (c == 0)
								{
									d2 = (d2 * 10) + (A[k].date[i] - '0');
								}
								if (c == 1)
								{
									m2 = (m2 * 10) + (A[k].date[i] - '0');
								}
								if (c == 2)
								{
									y2 = (y2 * 10) + (A[k].date[i] - '0');
								}
							}
						}
						else if (A[k].date[i] == '-')
						{
							c++;
						}
						i++;
					}
					if (A[k].date[i] == '\0')
					{
						if (d1 == d2&&m1 == m2&&y1 == y2)
						{
							count++;
							res = (struct transaction*)realloc(res, count*sizeof(struct transaction));
							res[r] = A[k];
							r++;
						}
					}
					k++;
					i = 0;
					c = 0;
					d2 = 0;
					m2 = 0;
					y2 = 0;
				}
			}
			j++;
			k = k - 2;
			i = 0;
			c = 0;
			d1 = 0;
			m1 = 0;
			y1 = 0;
			m2 = 0;
			d2 = 0;
			y2 = 0;
		}
		return res;
	}
}