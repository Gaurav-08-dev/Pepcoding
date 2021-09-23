bool merge(vector<vector<int>>& intervals) {
    
    if(intervals.size() <1) return true;
    sort(intervals.begin(),intervals.end());
    
    int sp=intervals[0][0];
    int ep=intervals[0][1];
    // cout<<intervals[0][0];
    for(int i=1;i<intervals.size();i++)
    {
        if(ep <= intervals[i][0])
        {
            sp=intervals[i][0];
            ep=intervals[i][1];
        }
        else
            return false;
    }
    
    return true;
}
