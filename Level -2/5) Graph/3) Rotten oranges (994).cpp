
#define pii pair<pair<int,int>,int>

    vector<int> xdir={-1,0,1,0};
    vector<int> ydir={0,-1,0,1}; 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int time=0;
        int oranges=0;
        queue<pii> q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 or grid[i][j]==2)
                {
                    oranges+=1;
                }
                if(grid[i][j]==2)
                {
                    q.push({{i,j},time});
                }
            }
        }
        
//         apply BFS 
         
        while(q.size())
        {
            pii p=q.front(); q.pop();
            
            int r=p.first.first;
            int c=p.first.second;
            int t=p.second;
            if(grid[r][c]==-2)
            {
                continue;
            }
            
            grid[r][c]=-2;
            oranges--;
            time=t;
            
            for(int d=0;d<4;d++)
            {
                int xd= r + xdir[d];
                int yd= c + ydir[d];
                if(xd>=0 and xd< grid.size() and yd>=0 and yd< grid[0].size() and grid[xd][yd]==1)
                    q.push({{xd,yd},time+1});
            }
            
        }
        
        return oranges==0 ? time:-1;
        
        
    
        
                
    }