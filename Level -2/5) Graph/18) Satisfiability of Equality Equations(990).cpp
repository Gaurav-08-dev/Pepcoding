    
    int find( vector<int> &parent,int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        
        return parent[node]=find(parent,parent[node]);
    }
    
    void unionn(int u, int v, vector<int> &parent,vector<int> &rank)
    {
	u=find(parent,u);
	v=find(parent,v);

	if(rank[u] < rank[v])
	{
		parent[v]=u;
	}
	else if(rank[v] < rank[u])
	{
		parent[u]=v;
	}
	else
	{
		parent[v]=u;
		rank[u]++;
	}
    }
    
    
    bool equationsPossible(vector<string>& equations) {
        
        int n=equations.size();
        
        vector<int> parent(26);
        vector<int> rank(26,0);
        
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]== '=')
            {
                int x=equations[i][0] - 'a';
                int y=equations[i][3] - 'a';
                
                int lx=find(parent,x);
                int ly=find(parent,y);
                
                if(lx==ly)
                {
                    continue;
                }
                
                unionn(lx,ly,parent,rank);
            }
        }
        
//         check set leader for != equality, if same then return false
        
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!')
            {
                int x=equations[i][0] - 'a';
                int y=equations[i][3] - 'a';
                
                int lx=find(parent,x);
                int ly=find(parent,y);
                
                if(lx==ly) return false;
                
                
            }    
        }
        
        return true;        
    }
