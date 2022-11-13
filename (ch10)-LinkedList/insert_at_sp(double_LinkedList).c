#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *newnode, *temp,*c,*p,*bef,*aft,*temp1,*temp2,*tail;
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

int search(int a)
{
    c=head;
    temp1=0;
    int k=0;
    while(c!=0)
    {
        if(c->data==a)
        {
            k=1;
            temp1=c;
            return 1;
            break;
        }
        c=c->next;
    }
       return 0;
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
r_viewnode()
{
    tail=temp;
    while(tail!=0)
    {
        printf("%d ",tail->data);
        tail=tail->prev;
    }
}


///--------------------------------

void inst(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=temp1=temp=newnode;
    }

    else
    {   if(temp1==0)
            {
                printf("\nInvalid position to insert\n");
            }
      else if(temp1->next!=0){
        temp2=temp1->next;
        newnode->prev=temp1;
        newnode->next=temp1->next;
        temp1->next=newnode;
        temp2->prev=newnode;}
        else{
               temp1->next=newnode;
               newnode->prev=temp1;
               temp=newnode;
            }
    }
}

sp(int l,int m){
 search(l);
 inst(m);

}



 void dlt(int x){
    int k=search(x);
if(k==1)
    {
        c=temp1;
    bef=c->prev;
    aft=c->next;


       if(bef==0)
            {
            aft->prev=0;
            free(c);
            head=aft;
            }
        else if(aft==0)
            {
            bef->next=0;
            temp=bef;
            free(c);
            }

        else{
            bef->next=c->next;
            aft->prev=c->prev;
            free(c);
            temp=aft;
            }
    }
}

///main
int main()
{
    struct node *newnode;
    int i, a, b, c, n,z=0,kk,key;
    head=0;
    while(scanf("%d",&n)==1)
    {
        insert(n);
    }
    printf("the list is: ");
    viewnode();
///for Search:

    key=1;//key to search a value
    kk=search(key);
if(kk==1)
        printf("\n%d Found",key);
    if(kk==0)
        printf("\n%d Not found",key);

///-----------

    printf("\nDeleate 1,5:");
         dlt(1);
         dlt(5);
    printf("\nUpdated list after deleate is:");
        viewnode();
        printf("\nspecific-position insert for 500 after 400:");
    sp(400,500);
    printf("\nUpdated list after specific-position insert is:");
        viewnode();
    printf("\nDeleate 9:");
    dlt(9);
    printf("\nUpdated list after deleate is:");
        viewnode();
    printf("\ninsert 10,11:");
insert(10);
insert(11);
printf("\nUpdated list after insert is:");
        viewnode();
         printf("\nspecific-position insert for 15 after 11:");
sp(11,15);
printf("\nUpdated list after specific-position insert is:");
        viewnode();
        printf("\ninsert 20:");
      insert(20);
      printf("\nUpdated list after insert is:");
    viewnode();
    printf("\nFinal list,reverse view:");
    r_viewnode();

}
// 1 2 3 4 5 6 7 8 9 ^z
