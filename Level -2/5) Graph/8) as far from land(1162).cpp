int maxDistance(vector<vector<int>>& grid) {
        
        
        int dist=0;
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> pii= q.front(); q.pop();
            
            pair<int,int> dirs[4]={{-1,0},{0,-1},{1,0},{0,1}};
            
            for(auto dir: dirs)
            {
                int row=pii.first + dir.first;
                int col=pii.second + dir.second;
                
                if(row>=0 and row<n and col>=0 and col<m and grid[row][col]==0)
                {
                    q.push({row,col});
                    grid[row][col]=grid[pii.first][pii.second]+1;
                    dist=max(grid[row][col],dist);
                    
                }
                
            }
            
        }
        
        return dist>0? dist-1: -1;
        
    }