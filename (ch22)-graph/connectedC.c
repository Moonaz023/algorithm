#include<stdio.h>
#include<string.h>
int v,e;
int graph[100][100];
int grapht[100][100];
int color[100];int colort[100];
int dis[100];int dist[100];
int finisht[100];int finishtt[100];
int ending[100],end=1;
int t=0;
int tt=0;
///------------------------------------
void dfs()
{
    int i,j,u;
    for(i=1;i<=v;i++)
    {
        color[i]=0;
    }
    t=0;
for(i=1;i<=v;i++)

{
    if(color[i]==0){
        dfs_visite(i);}
}

}
void dfs_visite(int u)
{
    t=t+1;
    dis[u]=t;
    color[u]=1;
    int V;
    for(V=1;V<=v;V++)
    {
        if(graph[u][V]==1 && color[V]==0)
        {
            dfs_visite(V);
        }
    }
    color[u]=2;
    t=t+1;

    finisht[u]=t;
    ending[end++]=u;
}
///------------------------------
void dfst()
{
    int i,j,u;
    for(i=1;i<=v;i++)
    {
        colort[i]=0;
    }
    t=0;
for(i=v;i>0;i--)
{
    if(colort[ending[i]]==0){
            if(i!=v)
        printf("--->");
        dfs_visitet(ending[i]);
        }
}

}
void dfs_visitet(int u)
{
    tt=tt+1;
    dist[u]=tt;
    colort[u]=1;
    int V;
    for(V=1;V<=v;V++)
    {
        if(grapht[u][V]==1 && colort[V]==0)
        {
            dfs_visitet(V);
        }
    }
    colort[u]=2;
    tt=tt+1;

    finishtt[u]=tt;
    ///-------------print SCC
    printf("%d",u);
}
int main()
{
    int i,j,s,d;
    freopen("scc.txt","r",stdin);
    scanf("%d %d",&v,&e);
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
            graph[i][j]=0;
            grapht[i][j]=0;
        }

    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&s,&d);
        graph[s][d]=1;
        grapht[d][s]=1;
        //graph[d][s]=1;
    }


    dfs();
    dfst();

}

/*
dfs2
7 8
6
5
1324

dfs1
124
3
6
5
*/
/*
my
8 13
1 2
2 3
3 4
4 3
5 1
2 5
2 6
3 7
4 8
5 6
6 7
7 6
7 8
*/
