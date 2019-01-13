#include<iostream>
using namespace std;

class node
{
    int info;
    node* next;
public:
    node* create(node*);
    void display(node*);
    void rev(node*);
    void rev2(node*);
    node* sortt(node*);
    node* ins_sort(node*);
};

node* node::create(node* start)
{
    node* cur;
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
        cur = start;
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

void node::rev(node* start)
{
    node n;
    node *p,*q,*r;
    q = NULL;
    p = start;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    start = q;
    n.display(start);
}

void node::rev2(node* start)
{
    node* cur  =start;
    node *temp, n;
    start = NULL;
    while(cur!=NULL)
    {
        temp = cur->next;
        cur->next = start;
        start = cur;
        cur = temp;
    }
    n.display(start);
}

node* node::sortt(node* start)
{
    node *p,*q;
    int x;
    q = start;
    while(q!=NULL)
    {
        p = q->next;
        while(p!=NULL)
        {
            if(q->info > p->info)
            {
                x = q->info;
                q->info = p->info;
                p->info = x;
            }
            p = p->next;
        }
        q = q->next;
    }
    return p;
}

node* node::ins_sort(node* start)
{
    node* cur = start;
    node* temp = new node;
    cout<<"Enter element: ";
    cin>>temp->info;
    while((cur->next)->info<temp->info)
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
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

int main()
{
    node* start = NULL;
    node n;
    for(int i=1 ; i<=5 ; i++)
    {
        start = n.create(start);
    }
    start = n.sortt(start);
    start = n.ins_sort(start);
    n.display(start);
}
