#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left,*right,*p;
};
struct node *root,*newnod;

void insert(int val)
{
     newnod = (struct node*) malloc(sizeof(struct node));
     struct node *current;
    struct node *y;
    y=NULL;
    newnod->key=val;
    newnod->left=newnod->right=NULL;
    current=root;

    while(current!=NULL)
    {
        y=current;
        if(newnod->key<current->key)
            current=current->left;
        else current=current->right;
    }
    newnod->p=y;
    if(y==NULL)
    {
        root=newnod;
    }
    else if(newnod->key<y->key)
    {
        y->left=newnod;
    }
    else
    {
         y->right=newnod;
    }


}

int mod=9999991,subtree[22];
long long int fact[22];
void sub(struct node* nod)
{
    if(nod==NULL)return;
    subtree[nod->key]=1;
    sub(nod->left);
    sub(nod->right);
    if(nod->left!=NULL)
    subtree[nod->key]+=subtree[nod->left->key];
    if(nod->right!=NULL)
    subtree[nod->key]+=subtree[nod->right->key];
}
long long int solve(struct node* nod)
{
    if(nod==NULL)return 1;
    int x=0,y=0;
    if(nod->left!=NULL)
    x=subtree[nod->left->key];
    if(nod->right!=NULL)
    y=subtree[nod->right->key];
    long long int z=fact[x+y]/(fact[x]*fact[y]);

    printf("---%d %d %d %d\n",nod->key,x,y,z);
    z%=mod;
    long long int ans= (solve(nod->left)%mod*solve(nod->right)%mod*z)%mod;
    free(nod);
    nod=NULL;
    return ans;
}
int main()
{
    int val,n,ts;
    scanf("%d",&ts);

    fact[0]=1;
    for(int i=1;i<=20;i++)fact[i]=fact[i-1]*i;
    while(ts--)
    {
        scanf("%d",&n);
        root=NULL;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val);
            insert(val);
        }
        sub(root);
        //for(int i=1;i<=n;i++)printf("//%d ",subtree[i]);
        printf("\n%d\n",solve(root));
    }
    //postorder(root);
    return 0;
}
