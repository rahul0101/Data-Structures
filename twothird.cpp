#include<iostream>
using namespace std;

class node
{
    int info;
    node* next;
public:
    node* create(node*);
    void display(node*);
    node* traverse(node*);
    node* counter(node*);
};

node* node::create(node* start)
{
    node* temp = new node;
    if(start == NULL)
    {
        cout<<"Enter element: \n";
        cin>>temp->info;
        temp->next = NULL;
        start = temp;
        temp = NULL;
    }
    else
    {
        node* cur = start;
        while(cur->next)
            cur = cur->next;
        cout<<"Enter element:\n";
        cin>>temp->info;
        temp->next = NULL;
        cur->next = temp;
        temp=cur=NULL;
    }
    return start;
}


void node::display(node* start)
{
    node* cur;
    if(start == NULL)
    {
        cout<<"Empty list...\n";
    }
    else
    {
        cur = start;
        while(cur)
        {
            cout<<cur->info<<"  ";
            cur=cur->next;
        }
        cur = NULL;
    }
    cout<<"\n";
}

node* node::counter(node* start)
{
    int c=0;
    node *cur = start,*st;
    while(cur!=NULL)
    {
        cur = cur->next;
        c++;
    }
    cur=start;
    for(int i=1;i<(2*c)/3;i++)
    {
        cur = cur->next;

    }
    st = cur->next;
    cur->next = NULL;
    cur=NULL;
    return st;
}

int main()
{
    node n,*start=NULL,*st=NULL;
    for(int i=1 ; i<=9 ; i++)
    {
        start = n.create(start);
    }
    st = n.counter(start);
    n.display(start);
    n.display(st);
}
