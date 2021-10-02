#include<bits/stdc++.h>
using namespace std;


// Representation using adjacencey matrix
void solve()
{
	int n,m;
	cin>>n>>m;

	// adjacent matrix
	int adj[n+1][n+1];

	// take edges as input

	for(int i=0;i<m;i++)
	{
		int u,v;

		cin>>u>>v;

		adj[u][v]=1;
		adj[v][u]=1;

	}

}


// representation using adjacency list
void adjacency_list()
{
	int n;  // no. of nodes
	int m; // no. of edges

	cin>>n>>m;
	//vector<int> adj[n+1]; // assuming 1 based indexing
	vector<pair<int,int>> adj[n];
	for(int i=0;i<m;i++)
	{
		int u,v, wt;
		cin>>u>>v>>wt;


		// if it's undirected graph

		// adj[u].push_back(v);
		// adj[v].push_back(u);

		// if it's directed graph
		
		// adj[u].push_back(v);


		// if it's weighted graph
		adj[u].push_back(make_pair(v,wt));
		adj[v].push_back(make_pair(u,wt));
	}


	for(int i=0;i<n;i++)
	{
		cout<<"Node " <<i<<" makes edge with "<<"\n";


		for(auto it=adj[i].begin();it!=adj[i].end();it++)
		{
			cout<<"\t"<<it->first<<" with edge weight of "<<it->second<<"\n";
		}

			cout<<"\n";
	}
}



int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    adjacency_list();

}