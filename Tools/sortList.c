#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int index;
    struct node *prev;
    struct node *next;
};
struct node *head, *newnode, *temp,*c,*p,*bef,*aft,*temp1,*temp2,*tail,*newhead,*min;

void inst(int data,int index)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->index=index;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=temp1=temp=newnode;
    }

    else
    {   temp=head;
        while(temp->next!=0 && temp->data <=newnode->data )
            {
                temp=temp->next;
            }
        if(temp->data <= newnode->data && temp->next==0){
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=0;

        }
        else if(temp->data > newnode->data && temp!=head){
               temp1=temp->prev;
               newnode->prev=temp1;
               temp1->next=newnode;
               temp->prev=newnode;
               newnode->next=temp;
            }
        else if(temp==head){

            newnode->next=temp;
            temp->prev=newnode;
            head=newnode;
        }
        else {
               temp1=temp->prev;
               newnode->prev=temp1;
               temp1->next=newnode;
               temp->prev=newnode;
               newnode->next=temp;
            }
    }
}

viewnode()
{
    p=head;
    while(p!=0)
    {
        printf("(%d %d)",p->data,p->index);
        p=p->next;
    }
}
int extract_min()
{
    int value=min->index;
    min=min->next;
    return value;
}
int main()
{
    int i,j;
    head=0;

    inst(1,0);
    inst(5,1);
    inst(7,2);
    inst(3,3);
    inst(9,4);
    inst(15,5);
    inst(12,6);
    inst(3,7);
    inst(9,8);
    inst(15,9);
    inst(12,10);
    inst(2,11);
    inst(9,12);
    inst(15,13);



viewnode();
min=head;

printf("\n\n");
int u=extract_min();
printf("%d ",u);
u=extract_min();
printf("%d ",u);
u=extract_min();
printf("%d ",u);

}
