/* TC - > O(NlogN) sc=O(N) */
int maxChunksToSorted(vector<int>& arr) {
    
    vector<int> v=arr;
    sort(v.begin(),v.end());
    
    long long sum1=0,sum2=0,ans=0;
    
    for(int i=0;i<arr.size();i++)
    {
        sum1+=arr[i];
        sum2+=v[i];
        
        if(sum1==sum2)
        {
            ans++;
        }
    }
    
    return ans;
}


/* without sorting */
int maxChunksToSorted(vector<int>& arr) {
    
    stack<int> st;
    int curr_max=0;
    for(int i=0;i<arr.size();i++)
    {
        curr_max=st.empty()? arr[i]: max(st.top(),arr[i]); 
        while(!st.empty() and st.top() > arr[i])
        {
            st.pop();
        }
        
        st.push(curr_max);
    }
    
    return st.size();
}