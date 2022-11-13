#include <limits.h>
#include <stdio.h>

int max(int a, int b)
 { return (a > b) ? a : b; }


int cutRod(int v[], int n,int s[])
{
	int c[n + 1];
	c[0] = 0;
	s[0]=0;
	int i, j;
	for (i = 1; i <= n; i++) {
		int  max_val= INT_MIN;

		for (j = 0; j < i; j++)
        {

			if(max_val<v[j]+c[i-j-1])
            {
                max_val=v[j]+c[i-j-1];
                s[i]=j+1;

            }


        }
		c[i] = max_val;
	}
//return c[n];
    printf("Maximum Obtainable Value is %d\n\n", c[n]);
}
void print(int v[],int n)
{
    int s[n+1];
    cutRod(v,n,s);

    printf("Optimum slices are : ");

    while(n>0)
    {
        printf("%d ",v[s[n]-1]);
        n=n-s[n];
    }
}

int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 },i;
	 int size = sizeof(arr) / sizeof(arr[0]);

    print(arr,size);

	return 0;
}



