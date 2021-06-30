#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,string>

void BFS(int n,vector<pair<int,int>> graph[],int src,string psf)
{
    vector<bool> visited(n);
    queue<pair<int,string>> q;
    
    q.push({src,psf});    
    // visited[src]=true;
    
    while(!q.empty())
    {
        pii node=q.front();
        q.pop();
        
        if(visited[node.first]==true)
        {
            continue;
        }
        else
        {
            // unvisited
            visited[node.first]=true;
            
        }
        
        cout<<node.first<<"@"<<node.second<<node.first<<"\n";
        
        
        
        for(auto it: graph[node.first])
        {
            if(!visited[it.first])
            {
                q.push({it.first,node.second+to_string(node.first)});
                
            }
        }
    }
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

	int src;
	cin>>src;
	
	BFS(n,adj,src,"");

}



int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    adjacency_list();

}