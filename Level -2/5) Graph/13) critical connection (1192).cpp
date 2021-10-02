#include<bits/stdc++.h>
using namespace std;



void dfs (int src,int parent,int &timer,vector<int> graph[],vector<bool> &visited,vector<int> &in,vector<int> &low,vector<vector<int>> &ans)
{
	visited[src]=true;
	in[src]=low[src]=timer;

	timer++;

	for(auto nbr: graph[src])
	{
		if(nbr==parent)
		{
			continue;
		}
		if(visited[nbr]==true)
		{
			low[src]=min(in[nbr],low[src]);
		}
		else 
		{
		    dfs(nbr,src,timer,graph,visited,in,low,ans);
			if(low[nbr] > in[src])
			{
			    ans.push_back({src,nbr});
				// cout<<src<<" - "<<nbr<<" is a bridge"<<"\n";
			}
			low[src]=min(low[nbr],low[src]);
		}
	}
}


int main()
{

	int n,m;
	cin>>n>>m;
	vector<int> graph[n];
	vector<bool> visited(n);
	vector<int> in(n);
	vector<int> low(n);
	int timer=0;
	while(m--)
	{
		int u,v;
		cin>>u>>v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<vector<int>> ans;dfs(0,-1,timer,graph,visited,in,low,ans);
	
	cout<<"[";
	for(int i=0;i<ans.size();i++)
	{
	    cout<<"[";
	    for(int j=0;j<ans[0].size();j++)
	    {
	        if(j==ans[0].size()-1)
	        {
	            cout<<ans[i][j]<<"]";
	        }
	        else
	        {
	            cout<<ans[i][j]<<", ";
	        }
	    }
	   if(i!=ans.size()-1)
	   cout<<", ";
	}
	cout<<"]";
}