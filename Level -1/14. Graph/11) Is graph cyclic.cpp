#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>


// method 2 using bfs
bool bfsForcycle(vector<pair<int,int>> graph[],int src,vector<bool> &visited)
{
	queue<pair<int,int>> q;

	visited[src]=true;
	q.push({src,-1});

	while(!q.empty())
	{
		int node=q.front().first;
		int par=q.front().second;

		q.pop();

		for(auto it: graph[node])
		{
			if(!visited[it.first])
			{
				visited[it.first]=true;
				q.push({it.first,node});
			}
			else if(par!=it.first)
			{
				return true;
			}
		}
	}
	return false;
}

// method 1 using BFS
/*
bool bfsForcycle(vector<pair<int,int>> graph[],int src,vector<int> &visited)
{
	queue<int> q;

	q.push(src);

	while(!q.empty())
	{
		int node=q.front();
		q.pop();

		if(visited[node]==true)
		{
			return true;
		}
		else{ visited[node]=true;}


		for(auto it: graph[node])
		{
			if(!visited[it.first]){
				q.push(it.first);
			}
		}
	}

	return false;
}*/


// Using DFS
bool dfsForCycle(vector<pair<int,int>> graph[],int src,vector<bool> &visited,int par)
{
    visited[src]=true;
    for(auto it: graph[src])
    {
        int nbr= it.first;
        
        if(visited[nbr]==true and nbr!=par)
        {
            return true;
        }
        if(visited[nbr]==false)
        {bool res=dfsForCycle(graph,nbr,visited,src);
            if(res==true)
        {
            return true;
        }
        }
    }
    
    return false;
}



bool isCyclic(int n,vector<pair<int,int>> graph[])
{
	vector<bool> visited(n);
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			if(bfsForcycle(graph,i,visited))
			{
				return true;
			}
		}
	}

	return false;
}

void solve()
{
	int n;  // no. of nodes
	int m; // no. of edges

	cin>>n>>m;

	vector<pair<int,int>> graph[n];
	for(int i=0;i<m;i++)
	{
		int u,v, wt;
		cin>>u>>v>>wt;

		graph[u].push_back(make_pair(v,wt));
		graph[v].push_back(make_pair(u,wt));
	}

	if(isCyclic(n,graph)) cout<<"true";
	else cout<<"false";


}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}