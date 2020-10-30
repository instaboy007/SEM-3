#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void bfs(vector<int> adj[],int src, int dest, int cost, int T,int N)
{

    int total_time[N+1];
    int wait[N+1];
    int path[N+1];
    for(int i=1;i<=N;i++)
    {
       path[i]=INT_MAX;
       wait[i]=0;
       total_time[i]=INT_MAX;
       sort(adj[i].begin(),adj[i].end());
    }
    total_time[src]=0;
   
    queue<int> Q;
    Q.push(src);
 
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
 
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(total_time[v]>total_time[u]+wait[u]+cost)
            {
                total_time[v]=total_time[u]+wait[u]+cost;
                wait[v]=T-(total_time[v]%T);
                path[v]=u;
                Q.push(v);
            }
        }
    }
    int j=dest;
    vector<int> ans;
    while(j!=src)
    {
        ans.push_back(j);
        j=path[j];
    }
    ans.push_back(src);
    int n=ans.size();
    cout<<n<<endl;
 
    for(int i=n-1;i>=0;i--)
    {
        cout<<ans[i]<<"->";
    }
}

int main()
{
    int N,M,T,C;
    cout<<"\nENTER THE VALUES OF N M T C:";
    cin>>N>>M>>T>>C;
    vector<int> adj[N+1];
    int u,v;
    cout<<"\nENTER THE VALUES:";
    for(int i=0;i<M;i++)
    {
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    cout<<"\nENTER THE VALUE OF X AND Y:";
    int src,dest;
    cin>>src>>dest;
    bfs(adj,src,dest,C,T,N);
}