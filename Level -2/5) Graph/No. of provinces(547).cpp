class Solution {
public:
    
    void dfs(vector<int> graph[],vector<bool>&visited,int node)
    {
        visited[node]=true;
        for(auto i: graph[node])
        {
               if(!visited[i]) dfs(graph,visited,i);
        }
    }
    int findCircleNum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n==0) return 0;
        vector<int> graph[n+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    graph[i].push_back(j);
                }
            }
        }
        
        int count=0;
        
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(graph,visited,i);
            }
        }
        
        return count;
        
    }
};