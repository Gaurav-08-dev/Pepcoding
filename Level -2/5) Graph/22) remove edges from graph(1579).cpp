class Solution {
public:
    
    
    int findparent(int node,vector<int> &parent)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findparent(parent[node],parent);
    }
    
    bool unionn(int u,int v,vector<int> &parent,vector<int> &rank)
{
    u=findparent(u,parent);
    v=findparent(v,parent);
    
    if(u!=v)
    {
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
        return true;
    }
    return false;
}
    
    bool static comp(vector<int> &a,vector<int>&b)
    {
        return a[0] > b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        
        sort(edges.begin(),edges.end(),comp);
        int countA=1;
        int countB=1;
        int rNode=0;
        
        vector<int> pA(n+1);
        vector<int> pB(n+1);
        vector<int> rA(n+1);
        vector<int> rB(n+1);
        
        for(int i=0;i<n;i++)
        {
            pA[i]=i;
            pB[i]=i;
            rA[i]=1;
            rB[i]=1;
        }
        
        for(vector<int> it:edges)
        {
            if(it[0]==3)
            {
                bool tempA=unionn(it[1],it[2],pA,rA);
                bool tempB=unionn(it[1],it[2],pB,rB);
                 if(tempA==true)
                countA++;
            
            if(tempB==true)
                countB++;
            if(tempA==false && tempB==false)
                rNode++;
            }
            else if(it[0]==1){
                bool tempA=unionn(it[1],it[2],pA,rA);
                
                if(tempA==true) countA++;
                else rNode++;
            }
            else{
                bool tempB=unionn(it[1],it[2],pB,rB);
                
                if(tempB==true) countB++;
                else rNode++;
            }
        }
        
        if(countA!=n or countB!=n)
        {
            return -1;
            
        }
        
        return rNode;
        
    }
};