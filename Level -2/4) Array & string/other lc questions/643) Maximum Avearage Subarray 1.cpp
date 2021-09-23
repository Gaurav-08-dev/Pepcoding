    double findMaxAverage(vector<int>& nums, int k) {
        
        int n=nums.size();
        int left=0,right=0;
        
        double avg=INT_MIN;
        double sum=0;
        while(right<n)
        {
            sum+=nums[right];
            if(right-left+1==k)
            {
                avg=max(avg,sum/k);
                sum-=nums[left];
                left++;
                
            }
            right++;
        }
        
        return avg;
        
    }