#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *newnode, *temp,*c,*p,*bef,*aft;
void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=temp=newnode;
    }

    else
    {
        temp->next=newnode;
        newnode->prev=temp;

        temp=temp->next;
    }
}

void search(int a)
{
    c=head;
    int k=0;
    while(c!=0)
    {
        if(c->data==a)
        {
            printf("\n%d Find",a);
            k=1;
            break;
        }
        c=c->next;
    }
    if(k==0)
        printf("\n%d not found",a);
}

viewnode()
{
    p=head;
    while(p!=0)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}


///delete

  void dlt(int x){
    c=head;
    //int k=0;
    while(c!=0){
        if(c->data==x){
            bef=c->prev;
            aft=c->next;
            break;
        }
       c=c->next;
    }

bef->next=c->next;
aft->prev=c->prev;
free(c);

}

///main
int main()
{
    struct node *newnode;
    int i, a, b, c, n;
    a=10;
    b=20;
    c=30;
    head=0;
    while(scanf("%lld",&n)==1)
    {
        insert(n);
    }
    printf("the list is:");
    viewnode();
    search(5);
    printf("\nUpdated list is:");
    dlt(9);
    viewnode();

}
