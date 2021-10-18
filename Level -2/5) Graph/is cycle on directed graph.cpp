
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



// using BFS -> KAHN's ALGO

bool isCyclic(int V, vector<int> adj[]) 
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
   
   int count=0;
   vector<int> visited(V,0);
   vector<int> ans;
   while(!q.empty())
   {
       int node=q.front(); q.pop();
       ans.push_back(node);
       count++;
       for(auto it: adj[node])
       {
           indegree[it]--;
           if(indegree[it]==0)
           {
               q.push(it);
           }
       }
   }

   if(count==V) return false;
   return true;
}