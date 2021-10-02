vector<int> xdir={-1,0,1,0};
vector<int> ydir={0,-1,0,1};    
void traverse(vector<vector<char>> &grid,int x, int y)
{
    grid[x][y]='0';
    for(int d=0;d<4;d++)
    {
        int row= x + xdir[d];
        int col= y + ydir[d];
        
        if(row>=0 and row<grid.size() and col>=0 and col<grid[0].size() and grid[row][col]!='0')
        {
            traverse(grid,row,col);
        }
        
    }
}

int numIslands(vector<vector<char>>& grid) {
    
    
    
    int row=grid.size(),col=grid[0].size();
    
    int islands=0;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]=='1')
            {
                islands++;
                traverse(grid,i,j);
                
            }
        }
    }
    
    return islands;
}