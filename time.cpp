#include<iostream>
using namespace std;
class time
{
public:
    int hour,min,sec;
    void read()
    {
        cout<<"Enter time in hh mm ss format: "<<"\n";
        cin>>hour>>min>>sec;
    }
    void display()
    {
        cout<<"Entered time is "<<hour<<':'<<min<<':'<<sec<<"\n";
    }
};

int main()
{
    time t1,t2;
    t1.read();
    t1.display();
    t2.read();
    t2.display();
    return 0;
}
