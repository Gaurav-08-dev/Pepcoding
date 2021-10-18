#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define tii pair<int,pair<int,string>>

// DIJKSTRA ALGO


void dijkstra(vector<pii> graph[],int n,int src)
{
	priority_queue<tii,vector<tii>,greater<tii>> q;
	q.push({0,{src,""+ to_string(src)}});
	vector<bool> visited(n);

	while(!q.empty())
	{
		// get + remove

		tii rem=q.top();
		q.pop();

		// mark

		if(visited[rem.second.first]==true)
		{
			continue;
		}

		visited[rem.second.first]=true;

		// work
		
		cout<<rem.second.first<<" via "<<rem.second.second<<" @ "<<rem.first<<"\n";

		// add neighbours

		for(auto it: graph[rem.second.first])
		{
			int nbr=it.first;
			if(visited[nbr]==false)
			{
				q.push({rem.first+it.second,{nbr,rem.second.second + to_string(nbr)}});
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

	dijkstra(graph,n,src);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}