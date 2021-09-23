    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
               
        int n=nums.size();
        vector<int> nextGreaterRight(n);
        stack<int> st; 
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and nums[st.top()]<nums[i])
            {
                int index=st.top(); st.pop();
                nextGreaterRight[index]=i;
            }
            st.push(i);
        }
        
        while(!st.empty()){
            nextGreaterRight[st.top()]=n;
            st.pop();
        }
        
        int i=0,j=0;
        int index=0;
 
        vector<int> result(n- (k-1));
        for(int i=0;i<result.size();i++)
        {
            if(j<i) j=i;
            
            while(nextGreaterRight[j]< i+k)
            {
                j=nextGreaterRight[j];
            }
            result[i]=nums[j];
        }
        
        return result;
        
    }   