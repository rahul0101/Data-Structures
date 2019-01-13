#include<iostream>
#include<stdlib.h>
using namespace std;

class dnode
{
    int info;
    dnode* prev;
    dnode* next;
public:
    dnode* create(dnode*,int);
    void display(dnode*);
    dnode* uni(dnode*, dnode*);
    dnode* inter(dnode*, dnode*);
    int isPresent(dnode* , int);
};

dnode* dnode::create(dnode* start, int x)
{
    dnode* temp = new dnode;
    temp->info = x;
    if(start == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
        temp = NULL;
    }
    else
    {
        dnode* cur = start;
        while(cur->next)
            cur = cur->next;
        temp->next = NULL;
        temp->prev = cur;
        cur->next = temp;
        temp=cur=NULL;
    }
    return start;
}

void dnode::display(dnode* start)
{
    dnode* cur;
    if(start == NULL)
    {
        cout<<"Empty list...\n";
    }
    else
    {
        cur = start;
        while(cur!=NULL)
        {
            cout<<cur->info<<"  ";
            cur=cur->next;
        }
        cur = NULL;
    }
    cout<<"\n";
}

dnode* dnode::uni(dnode* p, dnode* q)
{
    dnode n;
    dnode* res = NULL;
    while(p)
    {
        res = n.create(res,p->info);
        p = p->next;
    }
    while(q)
    {
        if (!isPresent(res, q->info))
            res = n.create(res,q->info);
        q = q->next;
    }
    return res;
}

dnode* dnode::inter(dnode* p, dnode* q)
{
    dnode n;
    dnode* res = NULL;
    while(p)
    {
        if(n.isPresent(q,p->info))
            res = n.create(res,p->info);
        p = p->next;
    }
    return res;
}

int dnode::isPresent(dnode* start, int x)
{
    dnode *t = start;
    while (t != NULL)
    {
        if (t->info == x)
            return 1;
        t = t->next;
    }
    return 0;
}

int main()
{
    dnode n, *p=NULL, *q=NULL, *start=NULL;
    int x;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter element";
        cin>>x;
        p=n.create(p,x);
    }
    n.display(p);
    for(int i=0;i<5;i++)
    {
        cout<<"Enter element";
        cin>>x;
        q=n.create(q,x);
    }
    n.display(q);
    cout<<endl;
    start=n.uni(p,q);
    n.display(start);
    cout<<endl;
    start=n.inter(p,q);
    n.display(start);
}
