#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *table[10];
void initializer_table()
{
   int i;
   for(i=0;i<=10;i++)
        table[i]=NULL;
}
void insert(int n)
{
  struct node *newnode=malloc(sizeof(struct node));
  newnode->data=n;
  newnode->next=NULL;
  int position=n%10;

  if(table[position]==NULL)
  {
      table[position]=newnode;
  }
  else
  {
    struct node *temp=table[position];
    while(temp->next)
    {
        temp=temp->next;

    }
    temp->next=newnode;
  }

}
void print()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("T_index[%d] ",i);
        struct node *temp=table[i];
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("NULL\n");
    }
}
int main()
{
    initializer_table();
     insert(5);
     insert(15);
     insert(19);
     insert(100);

    print();

}
