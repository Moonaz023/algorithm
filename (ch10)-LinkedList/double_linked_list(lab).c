#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	struct root *left;
	struct root *right;
	struct root *parent;
	int data;
};
struct node *root,*newnode,*temp,*pvt,*p2,*p,*sp,*t1;
int s=0;
void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=0;
    newnode->right=0;
    newnode->parent=0;
    p2=0;
    if(root==0)
    {
        root=temp=newnode;

    }

    else
    {  temp=root;
        while(temp!=0)
        {
        p2=temp;
        if(data>temp->data)
            {
                temp=temp->right;

            }
        else
            {
                temp=temp->left;

            }


        }

        if(data<p2->data)
        {
            p2->left=newnode;
            newnode->parent=p2;

        }
         if(data>p2->data)
        {
            p2->right=newnode;
            newnode->parent=p2;
        }
    }
}

void print3(struct node* print){
if(print!=0){
    if(print->left==0 && print->right==0 ){
        s=s+print->data;
        }
    print3(print->left);
     print3(print->right);

}
}

int main()
{
    int n,j=0,i,k;
    root=0;
scanf("%d",&i);
    while(j<i){
            scanf("%d",&n);
        insert(n);
        j++;
    }
    print3(root);
    printf("%d",s);
    return 0;
}
