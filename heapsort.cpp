#include<iostream>
using namespace std;
class H
{
public:
    void sort(int a[], int n)
    {
        int i,j,temp;
        adjust(a,1,n);
        for(i=n-1;i>0;i--)
        {
            temp = a[1];
            a[1] = a[i+1];
            a[i+1] = temp;
            adjust(a,1,i);
        }
    }
    void adjust(int a[], int p, int n)
    {
        int c,temp;
        temp = a[p];
        c = 2*p;
        while(c<=n)
        {
            if(c<n && a[c+1]>a[c])
                c++;
            if(temp>a[c])
                break;
            else
            {
                a[c/2] = a[c];
                c = 2*c;
            }
        }
        a[c/2] = temp;
        return;
    }
};

int main()
{
    H heap;
    int a[10];
    for(int j=1;j<6;j++)
    {
        cout<<"Enter element: ";
        cin>>a[j];
    }
    heap.sort(a,5);
    for(int i=1;i<6;i++)
        cout<<a[i]<<" ";
}











