#include<iostream>
#include<stdlib.h>
#define n 10
using namespace std;

class stack{
int i,ele,top,s[n],popele;
public:
stack(){top=-1;}

bool isempty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

void push(int x){
if(top==n-1){cout<<"overflow\n";}
else{s[++top]=x;cout<<x<<" added to stack\n";}
}
int pop(){
if(top==-1){cout<<"Underflow\n";return 0;}
else{return s[top--];}
}

void enqueue()
{
    cout<<"Enter element: \n";
cin>>ele;
    push(ele);
}

bool dequeue()
{
    if(!isempty())
    {
        popele = pop();
        if(!dequeue())
        {
            cout<<popele<<" removed from queue";
        }
        else
        {
            push(popele);
        }
        return true;
    }
    return false;
}

void display(){
for(i=0;i<=top;i++){cout<<s[i]<<' ';}
cout<<'\n';
}
};
int main(){
stack s;
int x;
char ch;
while(1){
cout<<"\n1.enqueue\n2.dequeue\n3.display\n4.exit\n";
cin>>ch;
switch(ch)
{
case '1':{s.enqueue();break;}
case '2':{s.dequeue();break;}
case '3':{s.display();break;}
case '4':{exit(0);}
}
}
return 0;
}
