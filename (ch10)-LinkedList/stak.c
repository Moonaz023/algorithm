#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *newnode, *temp,*c,*p,*bef,*aft,*tail,*newhead;
void pop(){
if(head!=0){
    if(tail->prev!=0){
temp=tail->prev;
temp->next=0;
free(tail);
tail=temp;
}
else if(tail->prev==0){
        printf("\nEmpty Stak");
temp=0;
free(tail);
tail=temp;
head=0;
}
}
else{
    printf("\nStak underflow\n");
}
}

void push(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=temp=tail=newnode;
    }

    else
    {
        temp->next=newnode;
        newnode->prev=temp;

        temp=temp->next;
    }
    tail=newnode;
}
///************************
viewnode()
{
    p=head;
    while(p!=0)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}


///main
int main()
{
    struct node *newnode;
    int i,n,comand;
    head=0;
 printf("\n press any key to oprtate\n");
 printf("\n 1)push 2)pop\n");
 printf("\n 3)stop operation\n");
//getchar();
while(1)
{
    printf("\nenter command: ");
    scanf("%d",&comand);
    if(comand==1)
        {     printf("\nEnter the value to Push: ");
            scanf("%d",&n);
                push(n);
                printf("\nUpdated list :");
                viewnode();

       }
       if(comand==2)
        {
            pop();
             printf("\nUpdated list :");
            viewnode();
        }


        if(comand==3)
        {
            break;
        }

}


}
//1 2 3 4 5 6 7 8 9
