#include<stdio.h>
 long int a[2000001],b[2000001],i,j,k,n,mx,c[150],cc;
int main()
{
    scanf("%ld",&n);
            mx=0;
        for(i=0;i<n;i++){
            scanf("%ld",&a[i]);
            if(a[i]>mx)
                mx=a[i];}
            for(i=0;i<=mx;i++)
                {
                  c[i]=0;
                }
            for(j=0;j<n;j++)
                c[a[j]]=c[a[j]]+1;

            for(i=1;i<=mx;i++)
                c[i]=c[i]+c[i-1];
            for(j=n-1;j>=0;j--)
            {
                b[c[a[j]]]=a[j];
                c[a[j]]=c[a[j]]-1;
            }
        for (cc = 1; cc <= n ; cc++)
            {
            printf("%ld", b[cc]);

            if(cc<(n))

            printf(" ");
            }

 printf("\n");

return 0;
}
/*
5
3 4 2 1 5
5
2 3 0 3 1
0
*/
