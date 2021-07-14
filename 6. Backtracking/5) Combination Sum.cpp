#include<bits/stdc++.h>
using namespace std;


// Time complexity: 2^n * k
class Solution {
public:
    
    void solve(vector<int> &candidates, int target,int index,vector<vector<int>> &ans,vector<int> &combinations)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(combinations);
            }
            return;
        }
        
        if(candidates[index]<=target)
        {
            combinations.push_back(candidates[index]);
            solve(candidates,target-candidates[index],index,ans,combinations);
            combinations.pop_back();
            
        }
        
        solve(candidates,target,index+1,ans,combinations);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combinations;
        
        solve(candidates,target,0,ans,combinations);
        return ans;
        
    }
};