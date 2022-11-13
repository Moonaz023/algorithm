#include<stdio.h>
#include<stdlib.h>
int vrtx;//number of vartex to map
char map[100][100];
int index=1;
int mapping(char vname[])
{
    int i,j;
    for(i=1;i<=vrtx;i++)
    {
        if(strcmp(map[i],vname)==0)
        {
            return i;
        }
    }
    strcpy(map[index++],vname);
    return index-1;
}
int main()
{
    return 0;
}
