#include<iostream>
using namespace std;
void dfs(int a[20][20], int n, int source)
{
    int visited[10],u,v,i;
    for(int i = 0;i<=n;i++)
        visited[i] = 0;
    int s[20],top=-1;
    s[++top] = source;
    visited[source] = 1;
    while(top>=0)
    {
        u = s[top--];
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                visited[v]=1;
                s[++top]=v;
            }
        }
        cout<<u<<" ";
    }
}

int main()
{
    int a[20][20],source,n,i,j;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix: ";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter source: ";
    cin>>source;
    cout<<"DFS: ";
    dfs(a,n,source);
}
