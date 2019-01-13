#include<iostream>
using namespace std;
class mstack{
int s[20],t[10],b[10],max=20,i,j,k;
public:
    void create_stack(int n){
    for(i=0;i<n;i++){
        t[i]=b[i]=((max/n)*i)-1;
    }
    b[i]=max-1;
    }

    int push(int n){
        int ele;
        cout<<"Enter stack number: "<<"\n";
    for(i=1;i<=n;i++){
        cout<<i<<" "<<"\n";
    }

    cin>>j;
    cout<<"Enter element: \n";
    cin>>ele;
    if(t[j-1]==b[j]){
        cout<<"overflow\n";
        return 0;
    }
    s[++t[j-1]]=ele;
    cout<<"Number added to stack\n";
    return 0;
    }

    int pop(int n){
        int ele;
        cout<<"Enter stack number: "<<"\n";
        for(i=1;i<=n;i++){
            cout<<i<<" "<<"\n";
        }
        cin>>j;
        if(t[j-1]==b[j-1]){return -999;}
        else {return s[t[j-1]--];}
    }

    int display(int n) {
        int ele;
        cout<<"Enter stack number: "<<"\n";
        for(i=1;i<=n;i++){
            cout<<i<<" "<<"\n";
        }
        cin>>j;
        if(t[j-1]==b[j-1])
        {
            cout<<"nothing to display\n";
            return 0;
        }
        else
        {
            for(k=b[j-1]+1;k<=t[j-1];k++){cout<<s[k]<<" ";cout<<"\n";}
            return 0;
        }
    }
};

int main(){
int n,x=0;
char ch;
mstack ms;
cout<<"Enter number of stacks: \n";
cin>>n;
ms.create_stack(n);
while(true){
    cout<<"\n1.push  2.pop  3.display\n";
    cin>>ch;
    if(ch=='1')
        ms.push(n);
    else if(ch=='2'){
        int p = ms.pop(n);
        cout<<p;
    }
    else if(ch=='3'){
        ms.display(n);
    }
}
return 0;
}
