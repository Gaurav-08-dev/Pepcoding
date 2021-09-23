int maxChunksToSorted(vector<int>& arr) {
    
    int max_index=0;
    int chunkCount=0;
    
    for(int i=0;i<arr.size();i++)
    {
        max_index=max(max_index,arr[i]);
        
        if(max_index==i)
        {
            chunkCount++;
        }
    }
    
    return chunkCount;
}