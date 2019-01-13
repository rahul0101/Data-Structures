#include<iostream>
using namespace std;
class queue
{
int max=5,front=-1,rear=-1,no,i;
int q[5];
public:
    void addq(){
        if(rear==max-1){
            cout<<"stack is full \n";
        }
        else{
            cout<<"enter number: \n";
            cin>>no;
            q[++rear]=no;
        }
    }

    void delq(){
    if(front==rear){
        cout<<"stack is empty\n";
    }
    else{
        cout<<q[++front]<<" removed from queue\n";
    }
    }

    void display(){
    for(i=front+1;i<=rear;i++){cout<<q[i]<<" ";}
    }
};

int main(){
    char ch;
    queue l;
    while(1)
{
cout<<"\n 1.add element";
cout<<"\n 2.remove element";
cout<<"\n 3.display";
cout<<"\n 4.exit";
cout<<"\n enter your choice:";
cin>>ch;
switch(ch)
{
case '1':
l.addq();
break;
case '2':
l.delq();
break;
case '3':
l.display();
break;
case '4':
break;
default:
cout<<"\n invalid choice";
}}
return 0;
}
