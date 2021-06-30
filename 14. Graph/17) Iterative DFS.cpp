#include<bits/stdc++.h>
using namespace std;


#define pii pair<int,int>
#define sii pair<int,string>

void iterative_DFS(vector<pii> graph[],int n,int src)
{
	vector<bool> visited(n);

	stack<sii> s;
	s.push({src,"" + to_string(src)});

	while(!s.empty())
	{
		sii nbr=s.top();
		s.pop();
		if(visited[nbr.first]==true)
		{
			continue;
		}
		visited[nbr.first]=true;

		cout<<nbr.first<<"@"<<nbr.second<<"\n";

		for(auto it: graph[nbr.first])
		{
			if(visited[it.first]==false)
			{
				s.push({it.first,nbr.second+to_string(it.first)});
			}
		}
	}
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

	int src;
	cin>>src;
	iterative_DFS(graph,n,src);

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}