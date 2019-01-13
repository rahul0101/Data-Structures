#include<iostream>
#include<string.h>
using namespace std;

class stk{
public:
    int top;
    node* s[10];
    stk(){top=-1;}
    void push(node* x)
    {
        s[++top] = x;
    }
    node pop()
    {
        return s[top--];
    }
};

class node{
int info;
node *lch, *rch;
public:
    node* create(node*);
    void display(node*,int);
    void in_iter(node*);
    void in_rec(node*);
    void pre_rec(node*);
    void post_rec(node*);
    int searchbt(node*, int);
    int parent(node*, int);
};

node* node::create(node* root)
{
    node *temp, *prev, *cur;
    char d[10];
    int i;
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

void node::in_rec(node* root)
{
    if(root==NULL)
        return ;
    in_rec(root->lch);
    cout<<root->info<<" ";
    in_rec(root->rch);
}

void node::pre_rec(node* root)
{
    if(root==NULL)
        return;
    cout<<root->info<<" ";
    pre_rec(root->lch);
    pre_rec(root->rch);
}

void node::post_rec(node* root)
{
    if(root==NULL)
        return;
    post_rec(root->lch);
    post_rec(root->rch);
    cout<<root->info<<" ";
}


void node::in_iter(node* r)
{
    stk st;
    while(1)
    {
        for(;r;r = r->lch)
            st.push(r);
        r = st.pop();
        if(!r)
            break;
        cout<<r->info<<"  ";
        r = r->lch;
    }
}

int node::searchbt(node* r, int x)
{
    int flag=0;
    stk st;
    while(1)
    {
        for(;r;r->lch)
            st.push(r->info);
        r->info = st.pop();
        if(!r)
            break;
        if(r->info==x){flag=1; return flag;}
        r = r->lch;
    }
    return flag;
}

int node::parent(node* root, int x)
{
    node *p;
    if(root==NULL)
    {
        return 0;
    }
    /*display(root->rch,level+1);
    for(int i=0;i<level;i++)
        cout<<"\t";
    cout<<root->info<<endl;
    display(root->lch,level+1);*/
    return 1;
}

int main()
{
    node *root=NULL,n;
    int x;
    cout<<"Enter number of nodes in binary tree: ";
    cin>>x;
    for(int i=0;i<x;i++)
    {
        root = n.create(root);
    }
    n.display(root,1);
    cout<<"\n\n";
    n.in_rec(root);
    /*cout<<"\n\n";
    n.pre_rec(root);
    cout<<"\n\n";
    n.post_rec(root);
    cout<<"\n\n";
    int z;
    cout<<"Enter element to be found: ";
    cin>>z;
    int f = n.searchbt(root,z);
    if(f==1)
        cout<<"Element found";
    else
        cout<<"Element not found";*/
}









