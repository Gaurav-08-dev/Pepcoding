class Solution {
public:
    
    int xdir[4]={-1,0,1,0};
    int ydir[4]={0,-1,0,1};
    
    void dfs(vector<vector<int>>& grid,int row,int col,vector<vector<bool>>& visited){        

        
        int count=0;
        
        int currentColor=grid[row][col];
       
        grid[row][col]*=-1;
        visited[row][col]=true;
        for(int d=0;d<4;d++)
        {
            int r=row + xdir[d];
            int c=col + ydir[d];
            
            if(r>=0 and r<grid.size() and c>=0 and c<grid[0].size()){
                if(grid[r][c]==currentColor or grid[r][c]==-currentColor)
                    count++;
                
                if(grid[r][c]==currentColor and visited[r][c]==false)
                    dfs(grid,r,c,visited);
                
            }
            
        }
        
        if(count==4) grid[row][col]*=-1;
                
    }
    
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        

        int r=grid.size();
        int c=grid[0].size();
        
        
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        
        dfs(grid,row,col,visited);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]<0)
                {
                    grid[i][j]=color;
                }
            }
        }
        
        
        return grid;
        
    }
};