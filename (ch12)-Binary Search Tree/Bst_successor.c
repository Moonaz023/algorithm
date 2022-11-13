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
struct node *root,*newnode,*temp,*pvt,*p2,*p,*sp;
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

///inroot
void print3(struct node* print){
if(print!=0){

    print3(print->left);
    printf("%d ",print->data);
     print3(print->right);

}
}
///sucessor
struct node* scr(struct node *s)
{
    if(s->right!=0)
    {   s=s->right;
        while(s->left!=0)
            s=s->left;
        return s;
    }
    sp=s->parent;
    while(sp!=0 && sp->right==s){
        s=sp;
        sp=sp->parent;
        if(sp==0){
            printf("not available");
            return 0;}
    }
    return sp;
}
///search
struct node *search(struct node* p,int f){
      if (p==0 || p->data==f)
      return p;
      if(f<p->data)
        return search(p->left,f);
        else
        return search(p->right,f);

}

int main()
{
    int n,i,j,k=6;
    root=0;

    while(scanf("%d",&n)==1){
        insert(n);
    }


printf("\n");
p=search(root,k);
pvt=scr(p);
if(pvt!=0)
printf("%d",pvt->data);

}
/*
10
6
12
4
8
11
13
7
9
^Z
*/
