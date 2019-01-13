#include <iostream>

using namespace std;

class node
{
	int info;
	node* next;
public:
	node* create(node*);
	node* find(node*);
	node* display(node*);
};
node* node::create(node* start)
{
	node* temp;
	cout<<"enqueue...\n";
	if(start==NULL)
	{
		cout<<"Queue was empty..Entering first element..\n";
		temp = new node;
		cout<<"Enter info..\n";
		cin>>temp->info;
		temp->next = NULL;
		start = temp;
		temp = NULL;
	}
	else
	{
		node* temp1;
		temp = start;
		while(temp->next)
		{
			temp = temp -> next;
		}
		temp1 = new node;
		temp1 -> next = NULL;
		cout<<"Enter information..\n";
		cin>>temp1->info;
		temp -> next = temp1;
		temp=temp1=NULL;
	}
	return start;
}
node* node::find(node* start)
{
	if(start == NULL)
	{
		cout<<"List empty..\n";
		return start;
	}
	else if(start->next == NULL)
	{
		cout<<"Only one element present.."<<start->info<<" \n";
		return start;
	}
	else
	{
		node* two=start;
		node* one=start;
		while(two && two->next)
		{
			two = (two->next)->next;
			one = one->next;
		}
		cout<<"Middle element is.."<<one->info<<"  \n";
		return start;
	}
}
node* node::display(node* start)
{
	node* temp;
	if(start==NULL)
	{
		cout<<"Queue empty..\n";
		return start;
	}
	else
	{
		temp = start;
		while(temp)
		{
			cout<<"  "<<temp->info<<" ";
			temp = temp -> next;
		}
		cout<<"\n";
		temp = NULL;
		return start;
	}
}
int main()
{
	node* start = NULL;
	node n;
	int ch=1,ch1;
	while(ch)
	{
		cout<<"\n\nEnter   1.create\n\t2.middle\n\t3.display\n\t4.Exit\n\n";
		cin>>ch1;
		switch(ch1)
		{
			case 1: cout<<"create..\n";
			start = n.create(start);
			break;
			case 2: cout<<"Middle..\n";
			start = n.find(start);
			break;
			case 3: cout<<"Displaying..\n";
			start = n.display(start);
			break;
			case 4: cout<<"Exit..\n";
			ch=0;
			break;
		}
	}
}
