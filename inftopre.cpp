#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class stkapp{
public:
char infix[30],chr,pfix[30],e1,e2,stck[20];
int i,j,p,top,p1;
    stkapp()
    {
        top=-1;
        p=0;
    }

    void push(char r)
    {
        stck[++top]=r;
    }

    bool isEmpty()
    {
        if(top==-1){return true;}
        return false;
    }

    char pop()
    {
        return stck[top--];
    }

    void getexp(){
        cout<<"Enter infix expression: ";
        gets(infix);
    }

    void convert()
    {
        strrev(infix);
        for(i=0;infix[i]!='\0';i++)
        {
            e1=infix[i];
            switch(e1)
            {
                case ')' : {push(e1);break;}
                case '(' : {while((e2=pop())!=')'){pfix[p++]=e2;}break;}
                case '+' :
                case '-' :
                case '*' :
                case '/' : {if(!isEmpty())
                           {
                               p1=prec(e1);
                               e2=pop();
                               while(p1<prec(e2)){
                                pfix[p++]=e2;
                                if(isEmpty())
                                    e2=pop();
                                else
                                    break;
                               }
                               if(p1>=prec(e2)){
                                push(e2);
                               }
                           }
                           push(e1);
                           break;
                           }
                default: pfix[p++] = e1;
            }}
            while(!isEmpty()){
                pfix[p++] = pop();
            }
            pfix[p]='\0';
    }

    int prec(char ch){
    switch(ch){
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;
        case ')' :return 1;
        default: return -1;
    }
    }

    void show(){
    cout<<"Postfix expression is:"<<endl;
    strrev(pfix);
    puts(pfix);
    }


};

int main()
{
    stkapp s;
    s.getexp();
    s.convert();
    s.show();
    return 0;
}

