
// using extra space
class Solution {
public:
    
    void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &perm,vector<int> &map)
    {
        if(perm.size()==nums.size())
        {
            ans.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(map[i]==0)
            {
                map[i]=1;
                perm.push_back(nums[i]);
                solve(nums,ans,perm,map);
                map[i]=0;
                perm.pop_back();
            }   
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> map(nums.size());
        solve(nums,ans,ds,map);
        
        return ans;
    }
};

// without using extra space

class Solution {
public:
    
    void solve(vector<int> &nums,int index,vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            swap(nums[index],nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        
        return ans;
    }
};
