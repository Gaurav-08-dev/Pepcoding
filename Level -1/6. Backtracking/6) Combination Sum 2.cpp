/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.

*/


/* brute force is based on combination sum 1; */

// the answer will be stored in set of list to avoid any duplicate combination 
// when we pick up elememt & increase index 


// efficient method

// Time complexity: 2^n * k(avearage length of combinations)
// space comlexity: k * x(no. of combinations)

class Solution {
public:

    void solve(vector<int> &candidates, int target,int index,vector<vector<int>> &ans,vector<int> &comb)
    {
        if(target==0)
        {
            ans.push_back(comb);
            return ;
        }
        
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index and candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target) break;
            comb.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,ans,comb);
            comb.pop_back();            
        }
    }
               
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        
        solve(candidates,target,0,ans,comb);
        return ans;
    }
};