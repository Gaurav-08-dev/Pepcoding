int findParent(vector<int> &parent,int node)
    {
        if(node== parent[node]){
            return node;
        }
        
        
        return parent[node]=findParent(parent,parent[node]);
    }
    
    
    void Union(vector<int> &parent,vector<int> &rank,int u, int v)
    {
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(rank[u] < rank[v])
        {
            parent[u]=v;
        }
        else if(rank[v] < rank[u])
        {
            parent[v]=u;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        
        int n=edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        
        
        for(auto edge: edges)
        {
            int u=edge[0],v=edge[1];
            int pu=findParent(parent,u);
            int pv=findParent(parent,v);
            if(pu == pv)
            {
                return edge;
            }
            
            Union(parent,rank,u,v);
        }
        return {};
    }