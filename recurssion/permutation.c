#include <stdio.h>

//function to print the array
void printarray(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        printarray(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));///tkhn e hobe jkhn condition fill fil korbe;
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);///swap hoile hobe
        swap((arr+i), (arr+start));
//        printf("last swap done......");
//        printarray(arr, end+1);
//        printf("......\n");
    }
}

int main()
{
    //taking input to the array
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int i;
    int arr[size];
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    //calling permutation function
    permutation(arr, 0, size-1);
    return 0;
}
