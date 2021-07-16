#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

// using BFS
bool isBipartiteComp(vector<pair<int,int>> graph[],int src,vector<int> &visited)
{
	queue<pair<int,int>> q;

	q.push({src,0});

	while(!q.empty())
	{
		pii rem=q.front();
		q.pop();

		if(visited[rem.first]!=-1)
		{
			// already discovered
			
			// 1. if again discovered with same level then continue

			if(visited[rem.first]==rem.second)
			{
				continue;
			}
			// 2. if again discovered but with different level -> return false, because odd size cycle is present
			else
			{

				return false;
			}
		}

		visited[rem.first]=rem.second;

		for(auto it: graph[rem.first])
		{
			int nbr=it.first;

			if(visited[nbr]==-1)
			{
				q.push({nbr,rem.second+1});
			}
		}
	}

	return true;
}	


// using DFS

bool isBipartiteComp(vector<pair<int,int>> graph[],int src,vector<int> &visited)
{
	if(visited[src]==-1)visited[src]=1;

	for(auto it: graph[src])
	{
		int nbr=it.first;

		if(visited[nbr]==-1 )
		{
			visited[nbr]=1-visited[src];

			if(!isBipartiteComp(graph,nbr,visited))
			{
				return false;
			}
		}
		else if(visited[nbr]==visited[src])
		{
			return false;
		}
	}

	return true;
}

bool isBipartite(vector<pair<int,int>> graph[],int n)
{
	vector<int> visited(n,-1);

	for(int i=0;i<n;i++)
	{
		if(visited[i]==-1)
		{
			bool res=isBipartiteComp(graph,i,visited);
			if(res==false)
			{
				return false;
			}
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

	if(isBipartite(graph,n))
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