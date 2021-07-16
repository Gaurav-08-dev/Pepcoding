#include<bits/stdc++.h>
using namespace std;

void BFS(int n,vector<int> graph[])
{
	vector<int> visited(n,0);

	queue<int> q;
	q.push(graph[0][0]);
	visited[graph[0][0]]=1;

	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		cout<<node<<" ";

		for(auto it: graph[node])
		{
			if(!visited[it])
			{
				// cout<<"it="<<it<<"\n";
				q.push(it);
				visited[it]=1;
			}
		}
	}

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
	
	cout<<"\n";
	cout<<"BFS: ";
	BFS(n,graph);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}