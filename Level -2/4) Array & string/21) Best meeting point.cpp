public static int minTotalDistance(int[][] grid) {
        // Write your code here
        
        
        ArrayList<Integer> xcord=new ArrayList<>();
        
        for(int r=0;r<grid.length;r++)
        {
            for(int c=0;c<grid[0].length;c++)
            {
                if(grid[r][c]==1) xcord.add(r);
            }
        }
        
        ArrayList<Integer> ycord=new ArrayList<>();
        
        for(int c=0;c<grid[0].length;c++)
        {
            for(int r=0;r<grid.length;r++)
            {
                if(grid[r][c]==1) ycord.add(c);
            }
        }
        
        
        // find meeting point
        
        int x=xcord.get(xcord.size()/2);
        int y=ycord.get(ycord.size()/2);
        
        int dist=0;
        
        for(int r=0;r<grid.length;r++)
        {
            for(int c=0;c<grid[0].length;c++)
            {
                if(grid[r][c]==1) 
                {
                    dist+=Math.abs(x-r) + Math.abs(y-c);
                }
            }
        }
        
        return dist;
    }