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
    node* del(node*);
    node* del_beg(node*);
    node* del_end(node*);
    node* del_2(node*);
    node* rev(node*);
};

node* node::create(node* start)
{
    node* temp = new node;
    cout<<"Enter element: \n";
    cin>>temp->info;
    if(start == NULL)
    {
        start = temp;
        temp->next = start;
        temp = NULL;
    }
    else
    {
        node* cur = start;
        while(cur->next!=start)
            cur = cur->next;
        temp->next = start;
        cur->next = temp;
        temp=cur=NULL;
    }
    return start;
}

node* node::ins_beg(node* start)
{
    node* temp = new node;
    cout<<"Enter element : ";
    cin>>temp->info;
    if(start == NULL)
    {
        start = temp;
        temp->next = start;
        temp = NULL;
    }
    else if(start->next==start)
    {
        temp->next=start;
        start->next=temp;
        start=temp;
        temp = NULL;
    }
    else
    {
        node* cur=start;
        while(cur->next!=start)
            cur=cur->next;
        temp->next=start;
        start=temp;
        cur->next=start;
        temp = cur = NULL;
    }
    return start;
}

node* node::ins_before(node* start)
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
        cout<<"Enter before which element? ";
        cin>>x;
        while((cur->next)->info != x)
        {
            cur = cur->next;
        }
        cout<<"Enter element to be inserted :";
        cin>>temp->info;
        temp->next = cur->next;
        cur->next = temp;
        if(x==start->info)
        {
            start = temp;
        }
    }
    cur=temp=NULL;
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
        while(cur->info != x)
        {
            cur = cur->next;
        }
        cout<<"Enter element to be inserted :";
        cin>>temp->info;
        temp->next = cur->next;
        cur->next = temp;
    }
    cur=temp=NULL;
    return start;
}

node* node::del(node* start)
{
    node *prev,*cur = start;
    if(start==NULL)
    {
        cout<<"Empty list.....";
    }
    else
    {
        int x;
        cout<<"Enter element to be deleted: ";
        cin>>x;
        while((cur)->info != x)
        {
            prev=cur;
            cur = cur->next;
        }
        if(cur == start){
        while(cur->next!=start)
        {
            cur=cur->next;
        }
        start = start->next;
        cur->next = start;
        cout<<"Element deleted...\n";
        }
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
        node *cur = start;
        while(cur->next!=start){cur=cur->next;}
        cur->next = start->next;
        start = start->next;
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
        while((cur->next)->next!=start)
            cur = cur->next;
        cur->next = start;
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
        cout<<cur->info<<"  ";
        cur = cur->next;
        while(cur!=start)
        {
            cout<<cur->info<<"  ";
            cur=cur->next;
        }
        cur = NULL;
    }
    cout<<"\n";
}

node* node::rev(node* start)
{

}

int main()
{
    node* start = NULL;
    node n;
    for(int i=1 ; i<=1 ; i++)
    {
        start = n.create(start);
    }
    //start = n.del(start);
    n.display(start);
}















