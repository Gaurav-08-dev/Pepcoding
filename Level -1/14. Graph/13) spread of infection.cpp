#include<bits/stdc++.h>
using namespace std;


int spreadInfection(int n,vector<pair<int,int>> graph[],int src,int time)
{
	int count=0;
	queue<pair<int,int>> q;
	vector< int> visited(n);

	q.push({src,1});

	while(!q.empty())
	{
		pair<int,int> rem=q.front();
		q.pop();

		if(visited[rem.first]!=0)
		{
			continue;
		}

		visited[rem.first]=rem.second;
		if(rem.second>time){
			break;
		}
		count++;

		for(auto it: graph[rem.first])
		{
			int nbr=it.first;
			if(visited[nbr]==0)
			{
				q.push({nbr,rem.second+1});
			}
		}
	}
	return count;
}

void solve()
{
		int n;  // no. of nodes
	int m; // no. of edges

	cin>>n>>m;

	vector<pair<int,int>> adj[n];
	for(int i=0;i<m;i++)
	{
		int u,v, wt;
		cin>>u>>v>>wt;

		adj[u].push_back(make_pair(v,wt));
		adj[v].push_back(make_pair(u,wt));
	}

	int src,time;
	cin>>src>>time;
	cout<<spreadInfection(n,adj,src,time)<<"\n";

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}