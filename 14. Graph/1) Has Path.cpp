#include<bits/stdc++.h>
using namespace std;

bool hasPath(int m,vector<pair<int,int>> adj[], int src, int dst, vector<bool> &visited)
{

	if(src==dst)
	{
		return true;
	}

	visited[src]=true;


		for(auto it=adj[src].begin();it!=adj[src].end();it++)
		{
			int nbr=it->first;

			if(visited[nbr]==false)
			{
				bool res=hasPath(m,adj,nbr,dst,visited);
				if(res==true)
				{
					return true;
				}
			}
	}


	return false;
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

		adj[u].push_back(make_pair(v,wt));
		adj[v].push_back(make_pair(u,wt));
	}

	int src,dst;
	cin>>src>>dst;
	vector<bool> visited(n);
	
	if(hasPath(m,adj,src,dst,visited))
		cout<<"true";
	else
		cout<<"false";


}



int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    adjacency_list();

}