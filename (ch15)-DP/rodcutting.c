#include <limits.h>
#include <stdio.h>

int max(int a, int b)
 { return (a > b) ? a : b; }


int cutRod(int v[], int n)
{
	int c[n + 1];
	c[0] = 0;
	int i, j;

	for (i = 1; i <= n; i++) {
		int  max_val= INT_MIN;

		for (j = 0; j < i; j++)
        {
			max_val = max(max_val, v[j] + c[i - j - 1]);

        }
		c[i] = max_val;
	}

	return c[n];
}


int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 },i;
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
	return 0;
}

