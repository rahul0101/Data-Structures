#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class pfix_ifix
{
    char stk[25][25],infix[50],pfix[50],res[20],op1[10],op2[10];
    int top;
public:
    pfix_ifix()
    {
        top=-1;
    }
    void push(char *a)
    {
        strcpy(stk[++top],a);
    }
    char* pop()
    {
        return stk[top--];
    }
    void getexp()
    {
        cout<<"Enter expression: ";
        gets(pfix);
    }
    void conv()
    {
        char sym[2];
        strrev(pfix);
        for(int i=0; pfix[i]!='\0';i++)
        {
            sym[0] = pfix[i];
            sym[1] = '\0';
            if(sym[0]=='+' || sym[0]=='-' || sym[0]=='*' || sym[0]=='/')
            {
                strcpy(op1,pop());
                strcpy(op2,pop());
                strcpy(res,"(");
                strcat(res,op1);
                strcat(res,sym);
                strcat(res,op2);
                strcat(res,")");
                push(res);
            }
            else
            {
                push(sym);
            }
        }
        strcpy(infix,pop());
        cout<<"infix expression: ";
        puts(infix);
    }
};

int main()
{
    pfix_ifix pi;
    pi.getexp();
    pi.conv();
    return 0;
}

