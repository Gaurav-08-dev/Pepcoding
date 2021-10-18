class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // int n=pre.size();
    vector<int> adj[n+1];
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        
        int V=n;
   // Find indegree of each node
   vector<int> indegree(V);
   for(int i=0;i<V;i++)
   {
       for(auto it: adj[i])
       {
           indegree[it]++;
       }
   }
   
        
   // take a queue
   int count=0;
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
       count++;
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
        
        if(count==V)
            return ans;
        
        return {};

    }
};