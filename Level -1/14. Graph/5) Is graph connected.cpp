#include<bits/stdc++.h>
using namespace std;

void gcc(vector<pair<int,int>> graph[],int n,vector<int> &visited,int src)
{
	visited[src]=true;

	for(auto it: graph[src])
	{
		int nbr=it.first;
		if(visited[nbr]==false)
		{
			gcc(graph,n,visited,nbr);
		}
	}
}

bool isConnected(vector<pair<int,int>> graph[],int n)
{
	int count=0;

	vector<int> visited(n);

	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			count++;
			if(count>1)
			{
				return false;
			}

			gcc(graph,n,visited,i);
		}
	}

	return true;
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

	if(isConnected(graph,n))
		cout<<"true";
	else
		cout<<"false";

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}