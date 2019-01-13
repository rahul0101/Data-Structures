#include<iostream>
using namespace std;
#define max 10
class heap
{
public:
    int insert(int a[],int n)
    {
        int c,p,item;
        cout<<"Enter element: ";
        cin>>item;
        c=n+1;
        p=c/2;
        if(c==max)
        {
            cout<<"Heap is full";
            return n;
        }
        while(c!=1 && item>a[p])
        {
            a[c] = a[p];
            c = p;
            p = c/2;
        }
        a[c] = item;
        return n+1;
    }

    int delheap(int a[],int n)
    {
        int c,p,item;
        if(n==0)
        {
            cout<<"Heap empty";
            return 0;
        }
        cout<<"Item deleted is: "<<a[1];
        int temp = a[n--];
        p=1;
        c=2*p;
        while(c<n)
        {
            if(c<=n)
            {
                if(a[c]<a[c+1])
                    c++;
            }
            if(temp>=a[c])
                break;
            a[p] = a[c];
            p=c;
            c=2*p;
        }
        a[p] = temp;
        return n;
    }
    void display(int a[], int n)
    {
        for(int i=1;i<n;i++)
            cout<<a[i]<<" ";
    }
};

int main()
{
    heap h;
    int a[max];
    int n=0;
    for(int i=0;i<=5;i++)
        n = h.insert(a,n);
    h.display(a,n);
}
