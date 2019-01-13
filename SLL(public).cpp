#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class list
{
    node *head, *tail;
public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    void create_node(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if(head==NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void insert_start(int value)
  {
    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
  }

    void display()
    {
        node *temp = new node;
        temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main()
{
    list x;
    for(int i=0 ; i<10 ; i++)
    {
        x.create_node(i*10);
    }
    for(int i=0 ; i<5 ; i++)
    {
        x.insert_start(i*10);
    }
    x.display();
    return 0;
}









