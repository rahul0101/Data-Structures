#include<iostream>
using namespace std;

class node
{
    int data;
    node* next;
public:
    node* create(node*);
    void display(node*);
    node* mergesort(node*,node*);
};

node* node::create(node* start)
{
    node* temp = new node;
    if(start == NULL)
    {
        cout<<"Enter element: \n";
        cin>>temp->data;
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
        cin>>temp->data;
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
            cout<<cur->data<<"  ";
            cur=cur->next;
        }
        cur = NULL;
    }
    cout<<"\n";
}

node* node::mergesort(node *p , node *q)
{
node *head3;
node *sorting = NULL;

	if(p == NULL)
		return q;
	if(q == NULL)
		return p;

	if(p && q)
	{
		if(p->data <= q->data)
		{
			sorting = p;
			p = sorting->next;
		}
		else
		{
			sorting = q;
			q = sorting->next;
		}

	}

	head3 = sorting;

	while(p && q)
	{
		if(p->data <= q->data)
		{
			sorting->next = p;
			sorting = p;
			p = sorting->next;
		}
		else
		{
			sorting->next = q;
			sorting = q;
			q = sorting->next;
		}
	}

	if(p==NULL)
	{
		sorting->next = q;
	}

	if(q==NULL)
	{
		sorting->next = p;
	}

	return head3;
}

int main()
{
    node n, *p=NULL, *q=NULL, *start=NULL;
    for(int i=0;i<5;i++)
    {
        p=n.create(p);
    }
    n.display(p);
    for(int i=0;i<5;i++)
    {
        q=n.create(q);
    }
    n.display(q);
    start=n.mergesort(p,q);
    n.display(start);
}
