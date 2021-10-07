int find(vector<int> &parent,int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=find(parent,parent[node]);
    }
    
    bool Union(vector<int> &parent,vector<int> &rank,int u, int v)
    {
        int pu=find(parent,u);
        int pv=find(parent,v);
         
        if(pu == pv)
        {
            return true;
        }
        else
        {
            if(rank[pu] > rank[pv])
            {
                parent[pv]=pu;
            }
            else if(rank[pv] > rank[pu])
            {
                parent[pu]=pv;
            }
            else
            {
                parent[pv]=parent[pu];
                rank[pu]++;
            }
        }
        return false;
        
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        
        vector<int> indegree(n+1,-1);
        
        int blackList1=-1,blackList2=-1;
        
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(indegree[v]==-1)
            {
                indegree[v]=i;
            }
            else
            {
                blackList1=i;
                blackList2=indegree[v];
                break;
            }
        }
        
        vector<int> parent(n+1);
        vector<int> rank(n+1,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        
        //apply dsu and avoid blacklist1 edge index and check if cyclic or not
        
        for(int i=0;i<n;i++)
        {
            if(i==blackList1) continue;
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            bool isCyclic=Union(parent,rank,u,v);
            if(isCyclic){
                if(blackList1==-1)
                {
                    return edges[i];
                }
                else
                {
                    return edges[blackList2];

                }
            }
        }
        
        
        return edges[blackList1];
        
    }