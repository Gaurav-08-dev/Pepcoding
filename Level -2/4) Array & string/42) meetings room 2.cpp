
int merge(vector<vector<int>>& intervals) {
    
    int n=intervals.size();    
    vector<int> start(n,0),end(n,0);
    for(int i=0;i<intervals.size();i++){

        start[i]=intervals[i][0];
        end[i]=intervals[i][1];
    }

   sort(start.begin(),start.end());
   sort(end.begin(),end.end());
   int maxRoom=0,curr_max=0;

   int i=0,j=0;
   
   while(i<n)
   {
    if(start[i]< end[j])
    {
         curr_max++;
         i++;
    }
    else
    {
        curr_max--;
        j++;
    }
    maxRoom=max(maxRoom,curr_max);
   }
    
    return maxRoom;
}
    