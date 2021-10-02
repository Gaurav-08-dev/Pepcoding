 void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size() or grid[i][j]!=1) return ;
        grid[i][j]=0;
        
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);        
        dfs(grid,i+1,j);        
        dfs(grid,i,j+1);        
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int count=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               if(i*j==0 or i==grid.size()-1 or j==grid[0].size()-1)
                   dfs(grid,i,j);
           }
       }
        
        for(int i=0;i<grid.size();i++)
        {
           for(int j=0;j<grid[0].size();j++)
           {
               if(grid[i][j]==1)
               {
                   count++;
               }
           }
        }
        return count;
    }