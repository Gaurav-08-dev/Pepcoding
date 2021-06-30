
// using DFS
bool isCycle(int src,vector<int> adj[],vector<int> &visited,vector<int> &dfsVisited)
	{
	    visited[src]=1; dfsVisited[src]=1;
	    
	    for(auto it: adj[src])
	    {
	        if(!visited[it])
	        {
	            if(isCycle(it,adj,visited,dfsVisited)) return true;
	        }
	        else if(dfsVisited[it]) return true;
	    }
	    
	    dfsVisited[src]=0;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> visited(V,0);
	   	vector<int> dfsVisited(V,0);
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!visited[i])
	   	    {
	   	        if(isCycle(i,adj,visited,dfsVisited))
	   	        {
	   	            return true;
	   	        }
	   	    }
	   	}
	   	
	   	return false;
	}



// using BFS

	