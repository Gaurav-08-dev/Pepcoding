#include<bits/stdc++.h>
using namespace std;


void getConnectedComp(vector<pair<int,int>> graph[],int src, vector<bool> &visited,vector<int> &comp)
{
	visited[src]=true;

	comp.push_back(src);

	for(auto it: graph[src])
	{
		int nbr=it.first;
		if(visited[nbr]==false)
		{
			getConnectedComp(graph,nbr,visited,comp);
		}
	}
}

vector<vector<int>> getConnectedComps(vector<pair<int,int>> graph[],int n)
{
	vector<vector<int>> comps;

	vector<bool> visited(n);

	for(int i=0;i<n;i++)
	{
		if(visited[i]==false){
			vector<int> comp;
			getConnectedComp(graph,i,visited,comp);
			comps.push_back(comp);
		}
	}

	return comps;
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

	
	vector<vector<int>> comps=getConnectedComps(graph,n);
	cout<<"[";
	for(int i=0;i<comps.size();i++)
	{
		cout<<"[";
		for(int j=0;j<comps[i].size();j++){
			if(j==comps[i].size()-1)
			{
				cout<<comps[i][j];
			}
			else
			{
				cout<<comps[i][j]<<",";
			}
		}
		if(i==comps.size()-1)
		{cout<<"]";}
		else
		{cout<<"]"<<",";}

	}
	cout<<"]";
}




int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}