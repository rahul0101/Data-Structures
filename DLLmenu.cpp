#include<iostream>
#include<stdlib.h>
using namespace std;

class dnode
{
    int info;
    dnode* prev;
    dnode* next;
public:
    dnode* create(dnode*);
    dnode* ins_bef(dnode*);
    dnode* ins_aft(dnode*);
    dnode* del(dnode*);
    void display(dnode*);
    dnode* rev(dnode*);
    dnode* uni(dnode*, dnode*);
    dnode* inter(dnode*, dndoe*);
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

dnode* dnode::ins_bef(dnode* start)
{
    dnode* cur=start;
    dnode* temp = new dnode;
    int x;
    cout<<"Enter before which element? ";
    cin>>x;
    cout<<"Enter element: \n";
    cin>>temp->info;
    if(start == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
        temp = NULL;
    }
    else if(x==start->info)
    {
        temp->prev=NULL;
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
    else
    {
        while((cur->next)->info!=x)
        {
            cur = cur->next;
        }
        temp->next = cur->next;
        (cur->next)->prev = temp;
        cur->next = temp;
        temp->prev = cur;
    }
    return start;
}



dnode* dnode::ins_aft(dnode* start)
{
    dnode* temp = new dnode;
    dnode* cur = start;
    while(cur->next)
        cur=cur->next;
    int x;
    cout<<"Enter after which element? ";
    cin>>x;
    cout<<"Enter element: \n";
    cin>>temp->info;
    if(start == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
        temp = NULL;
    }
    else if(x==start->info)
    {
        temp->next = start->next;
        (start->next)->prev = temp;
        temp->prev = start;
        start->next = temp;
    }
    else if(x==cur->info)
    {
        cur->next=temp;
        temp->prev=cur;
        temp->next=NULL;
    }
    else
    {
        cur = start;
        while(cur->info != x)
            cur=cur->next;
        temp->next = cur->next;
        (cur->next)->prev = temp;
        cur->next = temp;
        temp->prev = cur;
    }
    return start;
}

dnode* dnode::del(dnode* start)
{
    dnode* cur = start;
    int x;
    cout<<"Enter element to be deleted: ";
    cin>>x;
    if(start == NULL)
    {
        cout<<"Empty list...\n";
        return start;
    }
    else if(x==start->info)
    {
        start = start->next;
        delete(cur);
    }
    else
    {
        dnode* z;
        while((cur)->info != x)
        {
            cur = cur->next;
        }
        (cur->next)->prev = cur->prev;
        (cur->prev)->next = cur->next;
        delete(cur);
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

dnode* dnode::rev(dnode* start)
{
    dnode *p1,*p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while(p2)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    return p1;
}

int main()
{
    dnode *start=NULL, n;
    int a,x;
    cout<<"Enter number of elements: ";
    cin>>a;
    for(int i=0;i<a;i++)
    {
        start = n.create(start);
    }
    while(1)
    {
        cout<<"1.Insert before  2.Insert after  3.Delete  4.Traverse  5.Reverse  6.Exit \n";
        cin>>x;
        switch(x)
        {
        case 1:
            {
                start=n.ins_bef(start);break;
            }
        case 2:
            {
                start = n.ins_aft(start);break;
            }
        case 3:
            {
                start = n.del(start);break;
            }
        case 4:
            {
                n.display(start);break;
            }
        case 5:
            {
                start = n.rev(start);break;
            }
        case 6:
            {
                exit(0);
            }
        }
    }
}

