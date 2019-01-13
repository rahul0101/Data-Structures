#include<iostream>
using namespace std;

class node
{
    int info;
    node* next;
public:
    node* create(node*);
    node* ins_beg(node*);
    node* ins_after(node*);
    void display(node*);
    node* ins_before(node*);
    node* ins_pos(node*);
    node* del(node*);
    node* del_beg(node*);
    node* del_end(node*);
    node* del_2(node*);
};

node* node::create(node* start)
{
    node* temp = new node;
    cout<<"Enter element: \n";
    cin>>temp->info;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
        return start;
    }
    else
    {
        node* cur = start;
        while(cur->next)
            cur = cur->next;
        cur->next = temp;
    }
    return start;
}

node* node::ins_pos(node* start)
{
    node* temp = new node;
    cout<<"Enter element: \n";
    cin>>temp->info;
    if(start == NULL)
    {
        temp->next = NULL;
        start = temp;
        return start;
    }
    else
    {
        node *cur=start;
        int x;
        cout<<"Enter position of insertion: ";
        cin>>x;
        if(x==0)
        {
            temp->next = start;
            start = temp;
            return start;
        }
        for(int i=0;i<x-1;i++)
        {
            cur = cur->next;
        }
        temp->next=cur->next;
        cur->next = temp;
    }
    return start;
}

node* node::ins_beg(node* start)
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
        cout<<"Enter element : ";
        cin>>temp->info;
        temp->next = start;
        start = temp;
        temp = NULL;
    }
    return start;
}

node* node::ins_before(node* start)
{
    node *cur;
    node* temp = new node;
    int x;
    cout<<"Enter element to be inserted :";
    cin>>temp->info;
    if(start == NULL)
    {
        cout<<"Enter element: \n";
        cin>>temp->info;
        temp->next = NULL;
        start = temp;
        return start;
    }
    cout<<"Enter before which element? ";
    cin>>x;
    if(x==start->info)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        cur = start;
        while(cur->next)
        {
            if((cur->next)->info!= x )
                cur = cur->next;
        }
        if(!(cur->next)){cout<<"Element not found";return start;}
        temp->next = cur->next;
        cur->next = temp;
    }
    return start;
}

node* node::ins_after(node* start)
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
        int x;
        cout<<"Enter after which element? ";
        cin>>x;
        while(cur)
        {
            if((cur)->info!= x )
                cur = cur->next;
        }
        if(!(cur)){cout<<"Element not found";return start;}
        cout<<"Enter element to be inserted :";
        cin>>temp->info;
        temp->next = cur->next;
        cur->next = temp;
    }
    return start;
}

node* node::del(node* start)
{
    node *prev,*cur = start;
    int x;
    cout<<"Enter element to be deleted: ";
    cin>>x;
    while((cur->next)->next){cur = cur->next;}
    if(start==NULL)
    {
        cout<<"Empty list.....";
    }
    else if(cur->info == x)
    {
        prev = cur->next;
        cur->next = NULL;
        delete(prev);
    }
    else
    {
        cur = start;
        while((cur)->info != x)
        {
            prev=cur;
            cur = cur->next;
        }
        if(cur == start){start = start->next;cout<<"Element deleted...\n";}
        else if(cur==NULL){cout<<"Element not found...\n";}
        else{
        prev->next = cur->next;
        cur = prev = NULL;
        }
        return start;
    }
}

node* node::del_2(node* start)
{
    node *cur,*prev,*temp;
    if(start==NULL)
    {
        cout<<"Empty list.....";
    }
    else{
        cout<<"Enter element to be deleted: ";
        int x;
        cin>>x;
        cur = start;
        while(cur->info != x)
        {
            prev = cur; cur = cur->next;
        }
        temp->next = start;
        if(cur == start)
        {
            start = start->next;
        }
        else if(cur == NULL)
        {
            cout<<"Element not found";
        }
        else
        {
            prev->next = cur->next;
        }
    }
    cur = prev = temp = NULL;
    return start;
}
node* node::del_beg(node* start)
{
    if(start==NULL)
        cout<<"Empty list....";
    else{
        node* cur = start;
        start = start->next;
        delete(cur);
    }
    return start;
}

node* node::del_end(node* start)
{
    node* cur;
    if(start==NULL)
    {
        cout<<"Empty list...";
    }
    else
    {
        cur = start;
        while((cur->next)->next)
            cur = cur->next;
        delete(cur->next);
        cur->next = NULL;
        cur=NULL;
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

int main()
{
    node* start = NULL;
    node n;
    for(int i=1 ; i<6 ; i++)
    {
        start = n.create(start);
    }
    start = n.ins_after(start);
    n.display(start);
}















