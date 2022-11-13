#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ans=0;
int v,e,topology[100],t_index=1;
struct node{
    int data;
    struct node *next;
};
struct node *list[1000001];
void initializer_list()
{
   int i;
   for(i=0;i<=10;i++)
        list[i]=NULL;
}
void insert(int m,int n)
{
  struct node *newnode=malloc(sizeof(struct node));
  newnode->data=n;
  newnode->next=NULL;

  if(list[m]==NULL)
  {
      list[m]=newnode;
  }
  else
  {
    struct node *temp=list[m];
    while(temp->next)
    {
        temp=temp->next;

    }
    temp->next=newnode;
  }

}
int color[1000001];
int dis[1000001];
int predecessor[1000001];
int nxt[1000001];
int finisht[1000001];
char word[1000001];
int t=0;

void dfs(int start)
{
    int i,j,u;
    for(i=1;i<=v;i++)
    {
        color[i]=0;
        predecessor[i]=0;
    }
    t=0;

    i=start;

    while(1)
    {
        if(color[i]==0){
        dfs_visite(i);}
        //loop controll
        if(i<=v)
            i++;
        if(i>v)
            i=1;
        if(i==start)
            break;
    }
}
void dfs_visite(int u)
{
    t=t+1;
    dis[u]=t;
    color[u]=1;
    int V;
    struct node *temp=list[u];
            while(temp)
            {
            V=temp->data;
            if(color[V]==0)
            {
            predecessor[V]=u;
            nxt[u]=V;
            dfs_visite(V);
            }
            temp=temp->next;
            }
    color[u]=2;
    t=t+1;
    finisht[u]=t;
     topology[t_index++]=u;

}
int main()
{
    freopen("scc.txt","r",stdin);
    int st;
    int i,j,s,d;
    scanf("%d %d",&v,&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&s,&d);
        insert(s,d);
    }
    scanf("%d",&st);
    dfs(st);
    for(i=v;i>=1;i--)
    printf("%d ",topology[i]);

return 0;
}
/*
7 8 6 5 3 4 1 2
*/


