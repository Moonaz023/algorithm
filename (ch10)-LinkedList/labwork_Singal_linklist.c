#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;
void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
    }

    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}
viewnode()
{
    while(head!=0)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    struct node *newnode;
    int i, a, b, c, n;
    a=10;
    b=20;
    c=30;
    head=0;
         while(scanf("%d",&n)==1){
   insert(n);}
    viewnode();

}
