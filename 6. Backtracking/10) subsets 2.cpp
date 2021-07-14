class Solution {
public:
    
    void subsets(vector<int> &nums,int index,vector<int> &comb,vector<vector<int>> &ans)
    {
        ans.push_back(comb);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index and nums[i-1]==nums[i]) continue;
            comb.push_back(nums[i]);
            subsets(nums,i+1,comb,ans);
            comb.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<int> comb;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        subsets(nums,0,comb,ans);
        return ans;
    }
};