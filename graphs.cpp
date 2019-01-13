#include<iostream>
#include<string.h>
using namespace std;


class node{
public:
int info;
node *lch, *rch;
    node* create(node*);
    node* BFS(node*);
    node* DFS(node*);
};

class Q{
    int r,f;
    node* q[10];
public:
    Q()
    {
        r=f=-1;
    }
    void enqueue(node* z)
    {
        q[++r] = z;
    }
    node* dequeue()
    {
        return q[++f];
    }
    int isempty()
    {
        if(r==f)
            return 1;
        else
            return 0;
    }
};

node* node::create(node* root)
{
    node *temp, *prev, *cur;
    char d[10];
    int i,item;
    temp = new node;
    cout<<"Enter element: ";
    cin>>temp->info;
    temp->lch = NULL;
    temp->rch = NULL;
    if(root==NULL)
    {
        return temp;
    }
    cout<<"Direction: ";
    cin>>d;
    prev = NULL;
    cur = root;
    for(i=0;i<strlen(d);i++)
    {
        if(cur==NULL)
            break;
        prev = cur;
        if(d[i]=='l')
            cur = cur->lch;
        else
            cur = cur->rch;
    }
    if(cur!=NULL || i!=strlen(d))
    {
        cout<<"Impossible";
        delete(temp);
        return root;
    }
    if(d[i-1]=='l')
        prev->lch = temp;
    else
        prev->rch = temp;
    return root;
}

node* node::BFS(node* root)
{
    Q q;
    node* cur;
    cout<<"\n";
    q.enqueue(root);
    while(!q.isempty())
    {
        cur = q.dequeue();
        cout<<cur->info<<" ";
        if(cur->lch)
            q.enqueue(cur->lch);
        if(cur->rch)
            q.enqueue(cur->rch);
    }
}

node* node::DFS(node* root)
{
    if(root)
    {
        cout<<root->info<<" ";
        DFS(root->lch);
        DFS(root->rch);
    }
}

int main()
{
    node *root=NULL, *r=NULL,n;
    int x;
    cout<<"Enter number of nodes in binary tree: ";
    cin>>x;
    for(int i=0;i<x;i++)
    {
        root = n.create(root);
    }
    cout<<"\n";
    n.DFS(root);
}
