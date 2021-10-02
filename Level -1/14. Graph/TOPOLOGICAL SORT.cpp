// 	using dfs

void topo(int src,stack<int> &s,vector<int> adj[],vector<int> &visited)
	 {
	     visited[src]=1;
	     
	     for(auto it: adj[src])
	     {
	        if(!visited[it])
	        {
	            topo(it,s,adj,visited);
	        }
	     }
	     s.push(src);
	 }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    vector<int> visited(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	        {
	            topo(i,s,adj,visited);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}

/* *********************************************************************************** */

// using bfs -> Kahn's algorithm

vector<int> topoSort(int V, vector<int> adj[]) 
{
   // Find indegree of each node
   vector<int> indegree(V,0);
   for(int i=0;i<V;i++)
   {
       for(auto it: adj[i])
       {
           indegree[it]++;
       }
   }
   
   // take a queue
   
   queue<int> q;
   for(int i=0;i<V;i++)
   {
       if(indegree[i]==0)
       {
           q.push(i);
       }
   }
   
   vector<int> visited(V,0);
   vector<int> ans;
   while(!q.empty())
   {
       int node=q.front(); q.pop();
       ans.push_back(node);
       for(auto it: adj[node])
       {
           indegree[it]--;
           if(indegree[it]==0)
           {
               q.push(it);
           }
       }
   }
    return ans;
}




	/* Driver Code */

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


int main()
{
	adjacency_list();
}