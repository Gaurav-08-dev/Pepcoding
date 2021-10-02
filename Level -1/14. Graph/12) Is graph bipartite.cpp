#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>


// using BFS
/*bool bipartite(int src,vector<vector<int>> &graph,vector<int> &color)
{
    color[src]=1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty())
    {
        int node=q.front(); q.pop();
        
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1 - color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    
    return true;
}
*/

 /* using BFS - 2*/   
bool isBipartiteBFS(vector<pair<int,int>> graph[],int src,vector<int> &color)
{
	queue<pair<int,int>> q;

	q.push({src,0});

	while(!q.empty())
	{
		pii rem=q.front();
		q.pop();

		if(color[rem.first]!=-1)
		{
			// already discovered
			
			// 1. if again discovered with same level then continue

			if(color[rem.first]==rem.second)
			{
				continue;
			}
			// 2. if again discovered but with different level -> return false, because odd size cycle is present
			else
			{

				return false;
			}
		}

		color[rem.first]=rem.second;

		for(auto it: graph[rem.first])
		{
			int nbr=it.first;

			if(color[nbr]==-1)
			{
				q.push({nbr,rem.second+1});
			}
		}
	}

	return true;
}	


// using DFS

bool isBipartiteDFS(vector<pair<int,int>> graph[],int src,vector<int> &color)
{
	if(color[src]==-1)color[src]=1;

	for(auto it: graph[src])
	{
		int nbr=it.first;

		if(color[nbr]==-1 )
		{
			color[nbr]=1-color[src];

			if(!isBipartiteDFS(graph,nbr,color))
			{
				return false;
			}
		}
		else if(color[nbr]==color[src])
		{
			return false;
		}
	}

	return true;
}


bool isBipartite(vector<pair<int,int>> graph[],int n)
{
	vector<int> color(n,-1);

	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			bool res=isBipartiteDFS(graph,i,color);
			if(res==false)
			{
				return false;
			}
		}
	}
	return true;
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

	if(isBipartite(graph,n))
		cout<<"true";
	else
		cout<<"false";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}