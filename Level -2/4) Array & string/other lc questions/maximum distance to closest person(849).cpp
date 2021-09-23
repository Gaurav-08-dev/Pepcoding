    int maxDistToClosest(vector<int>& seats) {
        
        int leftEmptyseats=0;
        int longest=0;
        int index=0;
        
        while(seats[index]!=1)
        {
            leftEmptyseats++;
            index++;
        }
        
        int count=leftEmptyseats;
        for(;index<seats.size();index++)
        {
            if(seats[index]==0) count++;
            else
            {
                longest=max(count,longest);
                count=0;
            }
        }
        
        longest=longest%2==0 ? longest/2: longest/2 + 1;
        
        return max({longest,leftEmptyseats,count});
        
    }