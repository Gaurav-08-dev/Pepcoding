class Solution {
public:
    
   
    
    void dfsarticulation(int src,vector<int> graph[],vector<int> &parent,vector<int> &discovery,vector<int> &low,vector<bool> &visited,vector<vector<int>> &ans,int &time)
    {
        discovery[src]=low[src]=time;
        time++;
        visited[src]=true;
        int countForSource=0;
        
        for(int nbr: graph[src])
        {
            if(visited[nbr]==true and parent[src]!=nbr)
            {
                low[src]=min(low[src],discovery[nbr]);
            }
            else if(visited[nbr]==false)
            {
                parent[nbr]=src;
                dfsarticulation(nbr,graph,parent,discovery,low,visited,ans,time);
                low[src]=min(low[src],low[nbr]);
                countForSource++;
                // if(parent[src]==-1)
                // {
                //     if(countForSource > 1)
                //     {
                //         ans.push_back({src,nbr});
                //     }
                // }
                // else
                // {
                    if(discovery[src] < low[nbr])
                    {
                        ans.push_back({src,nbr});
                    }
                // }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
         if(n==2)
         {
             return connections;
         }
    vector<int> parent(n);
    vector<int> discovery(n);
    vector<int> low(n);
    vector<bool> visited(n);
    vector<vector<int>> ans;
        vector<int> graph[n];
        parent[0]=-1;
        int time=0;
         for(auto& conn : connections)
        {
            graph[conn[1]].push_back(conn[0]);
            graph[conn[0]].push_back(conn[1]);
        }
        
        dfsarticulation(0,graph,parent,discovery,low,visited,ans,time);
        return ans;
    }
};