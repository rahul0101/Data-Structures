#include<iostream>
#include<string.h>
using namespace std;

class node
{
    int info;
    node *lch, *rch;
    public:
        node* create(node*);
        void display(node*,int);
        node* srch(node*,int);
};

node* node::create(node* root)
{
    node* temp = new node;
    temp->lch = temp->rch = NULL;
    cout<<"Enter element: ";
    cin>>temp->info;
    if(root==NULL)
        return temp;
    node *p,*c=root;
    while(c)
    {
        p=c;
        if(temp->info<c->info)
            c = c->lch;
        else
            c=c->rch;
    }
    if(temp->info<p->info)
        p->lch = temp;
    else
        p->rch = temp;
    return root;
}

node* node::srch(node* root, int key)
{
    if (root == NULL || root->info == key)
        return root;

    if (root->info < key)
        return srch(root->rch, key);
    else
        return srch(root->lch, key);
}

void node::display(node* root, int level)
{
    if(root==NULL)
    {
        return;
    }
    display(root->rch,level+1);
    for(int i=0;i<level;i++)
        cout<<"\t";
    cout<<root->info<<endl;
    display(root->lch,level+1);
}

int main()
{
    node *root=NULL,n;
    int x,a;
    cout<<"Enter number of nodes in binary tree: ";
    cin>>x;
    for(int i=0;i<x;i++)
    {
        root = n.create(root);
    }
    n.display(root,1);
    cout<<endl;
    cout<<"Enter node to be found: ";
    cin>>a;
    node* sr = n.srch(root,a);
    if(sr){cout<<"Element found!!!!!";}
    else
        cout<<"Element not found";
}




