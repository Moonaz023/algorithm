#include<stdio.h>
#include<string.h>
int discovery[100],parent[100],graph[100][100];
//char map[100][100];
//int index=1;
//int mapping(char vname[])
//{
//    int i,j;
//    for(i=1;i<=vartex;i++)
//    {
//        if(strcmp(map[i],vname)==0)
//        {
//            return i;
//        }
//    }
//    strcpy(map[index++],vname);
//    return index-1;
//}
///****************relax
void relax(int u ,int v,int w)
{
    if(discovery[v]>discovery[u]+w)
    {
        discovery[v]=discovery[u]+w;
        parent[v]=u;
    }
}
int main()
{
  int s,d,wi,i,j,e,vartex;
    char source[100],dest[100];
    freopen("relax.txt","r",stdin);
    scanf("%d %d",&vartex,&e);
    for(i=1;i<=vartex;i++)
         for(j=1;j<=vartex;j++)
        {
            graph[i][j]=0;
        }
///-----------initialize
    for(i=1;i<=vartex;i++)
    {
        discovery[i]=999;
        parent[i]=0;
    }
    ///scan graph
    for(i=1;i<=e;i++)
    {
        scanf("%d %d %d",&s,&d,&wi);
        graph[s][d]=wi;
        //scanf("%s %s %d",&source,&dest,&wi);
        //s=mapping(source);
        //d=mapping(dest);
    }


///scan a source to start,now its 1 for try---initialize
discovery[1]=0;
for(i=1;i<=vartex;i++)
    for(j=1;j<=vartex;j++)
        {
            if(graph[i][j]!=0)
             relax(i,j,graph[i][j]);
        }

for(i=1;i<=vartex;i++)
    {
        printf("%d ", discovery[i]);

    }


}
