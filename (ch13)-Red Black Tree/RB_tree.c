#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	struct root *left;
	struct root *right;
	struct root *parent;
	int data;
	//char clr;
	int clr;///0=red;1=black
};
struct node *root,*newnode,*temp,*pvt,*p2,*p,*sp,*spp,*z,*y,*zp,*yp,*zpp,*fao;

void insert_fixup()
{
    z=newnode;
    zp=z->parent;
    zpp=zp->parent;
    root->clr=1;
    while(zp->clr==0 && z->clr==0)
    {
        if(zp==zpp->left)
        {
            y=zpp->right;
            if(y!=0 && y->clr==0)
            {
                zp->clr=1;
                y->clr=1;
                if(zpp!=root)
                {
                    zpp->clr=0;
                    z=zpp;
                    zp=z->parent;//not in book
                }
            }
            else
            {
                if(z==zp->right)
                {
                    left_rotate(zp);//line 11
                    zp=z->parent;
                    right_rotate(zp);
                    if(z!=root)
                    zp=z->parent;
                    z->clr=1;
                    fao=z->right;
                    fao->clr=0;
                }
                else
                {
                   right_rotate(zpp);
                   if(z!=root)
                   zp=z->parent;
                    zp->clr=1;
                    fao=zp->right;
                    fao->clr=0;

                }

            }

        }
        else//zp==zpp->right
        {
            y=zpp->left;
            if(y!=0 && y->clr==0)
            {
                zp->clr=1;
                y->clr=1;
                if(zpp!=root)
                {
                    zpp->clr=0;
                    z=zpp;
                    zp=z->parent;//not in book
                    zpp=zp->parent;//not in book
                }
            }
            else
            {
                if(z==zp->left)
                {
                    right_rotate(zp);//line 11
                    zp=z->parent;
                    left_rotate(zp);
                    if(z!=root)
                    zp=z->parent;
                    z->clr=1;
                    fao=z->left;
                    fao->clr=0;
                    //printf("yes %d\n",z->data);
                    fao=z->right;
                }
                else
                {
                   left_rotate(zpp);
                   if(z!=root)
                   zp=z->parent;
                    zp->clr=1;
                    fao=zp->left;
                    fao->clr=0;
                }

            }


        }
        root->clr=1;
    }

}
void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=0;
    newnode->right=0;
    newnode->parent=0;
    newnode->clr=0;//red
    // newnode->clr='r';
    p2=0;
    if(root==0)
    {
        root=temp=newnode;
        newnode->clr=1;
        //newnode->clr='b';

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
    if(newnode!=root)
    insert_fixup();
}

void left_rotate(struct node* x)
{
    struct node *y,*yl,*xp;
    y=x->right;
    x->right=y->left;
    if(y->left!=0){
        yl=(y->left);
        yl->parent=x;}
    y->parent=x->parent;
    xp=(x->parent);
    if(x->parent==0)
        root=y;
    else if(x==xp->left)
        xp->left=y;
    else
        xp->right=y;
    y->left=x;
    x->parent=y;
root->clr=1;
}
void right_rotate(struct node* x)
{
    struct node *y,*yr,*xp;
    y=x->left;
    x->left=y->right;
    if(y->right!=0){
        yr=(y->right);
        yr->parent=x;}
    y->parent=x->parent;
    xp=(x->parent);
    if(x->parent==0)
        root=y;
    else if(x==xp->right)
        xp->right=y;
    else
        xp->left=y;
    y->right=x;
    x->parent=y;
root->clr=1;
}

///preroot
void print1(struct node* p){
if(p!=0){
    printf("%d ",p->data);
    print1(p->left);
     print1(p->right);

}
}
///postroot
void print2(struct node* p){
if(p!=0){

    print2(p->left);
     print2(p->right);
printf("%d ",p->data);
}
}

///inroot
void print3(struct node* p){
if(p!=0){

    print3(p->left);
    printf("%d(%d) ",p->data,p->clr);
     print3(p->right);

}
}

int main()
{


        insert(10);
        insert(18);
        insert(7);
        insert(15);
        insert(16);
        insert(30);
        insert(25);
        insert(40);
        insert(60);
        insert(2);
        insert(1);
        insert(70);


printf("insert done\n");
printf("%d\n",root->data);
//print1(root);//pre root
//printf("\n");
//print2(root);//postroot
//printf("\n");
print3(root);//in root
printf("\n");
}
