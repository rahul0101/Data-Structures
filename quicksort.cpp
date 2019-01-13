#include<iostream>
using namespace std;
class sort
{
    public:
    void quick(int a[], int low, int high)
    {
        int pivot, i, j, temp;
        if(low<high)
        {
            i=low; j=high+1;
            pivot = a[low];
            do{
                do{
                    i++;
                }while(a[i]<pivot);
                do{
                    j--;
                }while(a[j]>pivot);
                if(i<j)
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }while(i<j);
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            quick(a,low,j-1);
            quick(a,j+1,high);
        }
    }
};

int main()
{
    sort n;
    int a[10];
    for(int i=0 ; i<5 ; i++)
    {
        cin>>a[i];
    }
    n.quick(a,0,4);
    for(int i=0 ; i<5 ; i++)
    {
        cout<<a[i]<<" ";
    }
}
