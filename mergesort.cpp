#include<iostream>
using namespace std;
class mer
{
    public:
    void merge(int a[], int n)
    {
        int len = 1;
        int s[10];
        while(len<n)
        {
            merge_pass(a,s,n,len);
            len = len*2;
            merge_pass(s,a,n,len);
            len = len*2;
        }
    }

    void merge_pass(int a[], int s[], int n, int len)
    {
        int i,j;
        for(i=0;i<=n-2*len;i=i+2*len)
            mergesort(a,s,i,i+len-1,i+2*len-1);
        if((i+len)<n)
            mergesort(a,s,i,i+len-1,n-1);
        else{
            for(j=i;j<n;j++){
                s[j]=a[i];
            }
        }
    }

    void mergesort(int a[], int s[], int i, int m, int n)
    {
        int j,k;
        j=m+1;
        k=i;
        while(i<=m && j<=n)
        {
            if(a[i]<=a[j])
                s[k++] = a[i++];
            else
                s[k++] = a[j++];
        }
        while(i<=m)
            s[k++] = a[i++];
        while(j<=n)
            s[k++] = a[j++];
    }
};

int main()
{
    mer n;
    int a[10];
    for(int i=0 ; i<5 ; i++)
    {
        cin>>a[i];
    }
    n.merge(a,5);
    for(int i=0 ; i<5 ; i++)
    {
        cout<<a[i]<<" ";
    }
}






