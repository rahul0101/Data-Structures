#include<iostream>
using namespace std;

class dnode
{
    int info;
    dnode* prev;
    dnode* next;
public:
    dnode* create(dnode*);
    void display(dnode*);
};

dnode* dnode::create(dnode* start)
{
    dnode* temp = new dnode;
    cout<<"Enter element: \n";
    cin>>temp->info;
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

int main()
{
    dnode *start=NULL,n;
    for(int i=1 ; i<6 ; i++)
    {
        start = n.create(start);
    }
    n.display(start);
}

