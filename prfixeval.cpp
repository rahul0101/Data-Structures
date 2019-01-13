#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
class pf
{
    char pfix[30];
    int op1,op2,stk[30],top,res,count=0;
public:
    pf()
    {
        top=-1;
    }
    void push(int x)
    {
        stk[++top]=x;
    }
    int pop()
    {
        return stk[top--];
    }
    void getexp()
    {
        cout<<"Enter prefix expression:\n";
        gets(pfix);
    }
    void eval()
    {
        strrev(pfix);
        for(int i=0;pfix[i]!='\0';i++)
        {
            if(isdigit(pfix[i]))
            {
                push(pfix[i]-'0');
            }
            else
            {
                op1=pop();
                op2=pop();
                switch(pfix[i])
                {
                    case '+':{res=op1+op2;break;}
                    case '-':{res=op1-op2;break;}
                    case '*':{res=op1*op2;break;}
                    case '/':{res=op1/op2;break;}
                }
                push(res);
            }
        }
    }
    void getres()
    {
        cout<<pop();
    }
};

int main()
{
    pf eq;
    eq.getexp();
    eq.eval();
    eq.getres();
    return 0;
}
