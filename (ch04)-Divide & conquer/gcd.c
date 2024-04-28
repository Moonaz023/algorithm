#include <stdio.h>

int main()
{

    int n1, n2, i, GCD_Num;
    printf ( " Enter any two numbers: \n ");
    scanf ( "%d %d", &n1, &n2);

    
    for( i = 1; i <= n1 && i <= n2; ++i)
    {
        if (n1 % i ==0 && n2 % i == 0)
            GCD_Num = i; /* if n1 and n2 is completely divisible by i, the divisible number will be the GCD_Num */
    }
    
    printf (" GCD of two numbers %d and %d is %d.", n1, n2, GCD_Num);
    return 0;
}
/*

#include <stdio.h>
int hcf(int n1, int n2);
int main() {
    int n1, n2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    printf("G.C.D of %d and %d is %d.", n1, n2, hcf(n1, n2));
    return 0;
}

int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}


*/
