#include<iostream>
#include<stdio.h>
using namespace std;
class student
{
public:
    char name[30];
    int roll,i,j,k;
    char grade;

    void read()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter roll no: ";
        cin>>roll;
        cout<<"Enter grade: ";
        cin>>grade;
        cout<<"\n";
    }

    void display()
    {
        cout<<"Name of student: "<<name<<endl;
        cout<<"Roll no. of student: "<<roll<<endl;
        cout<<"Grade of student: "<<grade<<"\n";
    }
};

int main()
{
    int i,n;
    student s[10];
    cout<<"Enter number of students: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        s[i].read();
    }
    for(i=0;i<n;i++)
    {
        s[i].display();
    }
    return 0;
}
