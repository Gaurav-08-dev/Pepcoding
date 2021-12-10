class Solution {
public:
    
    bool isValid(vector<int>& nums, int mid,int m){
        
        int sub=1,subSum=0;
        
        for(int i:nums){
            subSum+=i;
            if(subSum>mid){
                subSum=i;
                sub++;
            }
            if(sub>m) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int left=INT_MIN,right=0;
        
        for(int i:nums){
            left=max(left,i);
            right+=i;
        }
        
        int ans=0;
        while(left<=right){
            
            int mid=left + (right-left)/2;
            
            if(isValid(nums,mid,m)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        
        return ans;
    }
};