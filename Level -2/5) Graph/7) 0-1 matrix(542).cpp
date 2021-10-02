vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size(),m=mat[0].size();
        
        vector<int> xdir={-1,0,1,0};
        vector<int> ydir={0,-1,0,1};
        
        vector<vector<int>> res(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            for(int d=0;d<4;d++)
            {
                int row=it.first + xdir[d];
                int col=it.second + ydir[d];
                
                if(row>=0 and col>=0 and row<n and col<m)
                {
                    if(res[row][col] > res[it.first][it.second])
                    {
                        res[row][col]=res[it.first][it.second]+1;
                        q.push({row,col});
                    }
                }
                
            }
        }
        
        return res;
        
    }