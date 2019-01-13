#include<iostream>
using namespace std;
class R
{
public:
    int countdig(int a[],int n)
    {
        int cnt=0,max=0;
        for(int i=0;i<n;i++)
        {
            while(a[i]!=0)
            {
                a[i] = a[i]/10;
                cnt++;
            }
            if(max<cnt)
                max = cnt;
            cnt=0;
        }
        return max;
    }
    void sort(int a[], int a1[], int n)
    {
        int k,i,min,t,temp,dig;
        dig = countdig(a,n);
        for(k=0;k<dig;k++)
        {
            for(i=0;i<n-1;i++)
            {
                min = a[i]%10;
                t=i;
                for(int j=i+1;j<n;j++)
                {
                    if(min>a[j]%10)
                    {
                        min = a[j]%10;
                        t=j;
                    }
                }
                temp=a1[t];
                a1[t]=a1[i];
                a1[i]=temp;
                temp=a[t];
                a[t]=a[i];
                a[i]=temp;
            }
            for(int j=0;j<n;j++)
            {
                a[j] = a[j]/10;
            }
        }
        cout<<"Sorted array: "<<endl;
        for(i=0;i<n;i++)
            cout<<a1[i]<<" ";
    }
};

int main()
{
    R radix;
    int a[10],a1[10],i,x;
    for(int i=0;i<5;i++)
    {
        cin>>x;
        a[i]=a1[i]=x;
    }
    radix.sort(a,a1,5);
}












