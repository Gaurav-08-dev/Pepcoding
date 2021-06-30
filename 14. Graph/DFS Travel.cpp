#include<bits/stdc++.h>
using namespace std;

void DFS(int start,vector<int> graph[],vector<bool> &visited)
{
	visited[start]=true;

	for(auto it:graph[start])
	{
		if(!visited[it])
		{
			DFS(it,graph,visited);
		}
	}
	cout<<start<<" ";

}


void solve()
{
	int n,m,wt;

	cin>>n>>m;

	vector<int> graph[n];
	for(int i=0;i<m;i++)
	{
		int u,v;

		cin>>u>>v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=0;i<n;i++)
	{
		cout<<i<<" : ";
		for(auto it:graph[i])
		{
			cout<<it<<" ";
		}
		cout<<"\n";
	}
	vector<bool> visited(n);
	cout<<"\n";
	cout<<"DFS: ";
	DFS(2,graph,visited);	
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}