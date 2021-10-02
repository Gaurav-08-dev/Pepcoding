#include<bits/stdc++.h>
using namespace std;

void dfs_count(vector<int> graph[],int src,vector<bool> &visited,int &count)
{
    visited[src]=true;
    count++;
    for(auto nbr: graph[src])
    {
        if(visited[nbr]==false)
        {
            dfs_count(graph,nbr,visited,count);
        }
    }
}

void dfs_stack(vector<int> graph[],int src,vector<bool> &visited,stack<int> &st)
{
    visited[src]=true;
    
    for(int nbr: graph[src])
    {
        if(visited[nbr]==false)
        {
            dfs_stack(graph,nbr,visited,st);
        }
    }
    st.push(src);
}





int solve(vector<int> graph[],int n)
{
    vector<bool> visited(n);
    stack<int> st;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs_stack(graph,i,visited,st);
        }
    }
    
    int top=st.top();
    vector<bool> visit(n);
    dfs_count(graph,top,visit,count);
    return count==n?top : -1;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    cout<<solve(graph,n);
    
}