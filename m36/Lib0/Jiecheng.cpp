#include "pch.h"
#include "framework.h"
int factorial(int n)
{
	int i, j = 1;
	if (n < 10)
	{
		for (i = 1; i<=n; i++)
		{
			j *= i;
		}
		return j;
	}
}