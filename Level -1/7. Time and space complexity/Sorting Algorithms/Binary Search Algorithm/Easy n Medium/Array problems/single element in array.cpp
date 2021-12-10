class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        
        int start=0, end=nums.size()-2;
        
        while(start <= end)
        {
            int mid=start + (end-start)/2;
            cout<<!(mid%2)<<"\n";
            
            if((mid%2 and nums[mid]==nums[mid-1]) or (!(mid%2) and nums[mid]==nums[mid+1]))
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return nums[start];
    }
};