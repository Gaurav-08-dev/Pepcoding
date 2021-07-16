#include<bits/stdc++.h>
using namespace std;

void hasPath(vector<pair<int,int>> adj[], int src, int dst, vector<bool> &visited,string psf)
{

	if(src==dst)
	{
		psf+=to_string(src);
		cout<<psf<<"\n";
		return;
	}
	visited[src]=true;

	for(auto it: adj[src])
	{
		int nbr=it.first;
		if(visited[nbr]==false)
		{
			hasPath(adj,nbr,dst,visited,psf+ to_string(src));
		}
	}
	visited[src]=false;
}

// representation using adjacency list
void adjacency_list()
{
	int n;  // no. of nodes
	int m; // no. of edges

	cin>>n>>m;

	vector<pair<int,int>> adj[n];
	for(int i=0;i<m;i++)
	{
		int u,v, wt;
		cin>>u>>v>>wt;

		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}

	int src,dst;
	cin>>src>>dst;
	vector<bool> visited(n);
	
	hasPath(adj,src,dst,visited,"");
	

}



int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    adjacency_list();

}