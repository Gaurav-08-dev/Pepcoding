class Solution {
public:
    
    vector<int> xdir={-1,0,1,0};
    vector<int> ydir={0,-1,0,1};
    
    void dfs(vector<vector<int>> &grid,queue<pair<int,int>> &q,int i,int j)
    {
        grid[i][j]=-1;
        q.push({i,j});
        for(int d=0;d<4;d++)
        {
            int row=i + xdir[d];
            int col=j + ydir[d];
            
            if(row>=0 and row<grid.size() and col>=0 and col<grid[0].size() and grid[row][col]==1)
            {
                dfs(grid,q,row,col);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        
        
         for(int i=0;i<grid.size();i++)
        {
            bool flag=true;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,q,i,j);
                    flag=false;
                        break;
                }
            }
            
            if(flag==false)
                break;
        }
        
        int level=-1;
        
        while(!q.empty())
        {
            int size=q.size();
            level++;
            while(size--)
            {
                pair<int,int> pii=q.front(); q.pop();
                
                for(int d=0;d<4;d++)
                {
                    int row=pii.first + xdir[d];
                    int col=pii.second + ydir[d];
                    
                    if(row>=0 and row<grid.size() and col>=0 and col<grid[0].size() and grid[row][col]!=-1)
                    {
                        if(grid[row][col]==1)
                        {
                            return level;
                        }
                        grid[row][col]=-1;
                        q.push({row,col});
                    }
                    
                }
            }
        }
        
        
        
        return -1;
    }
};