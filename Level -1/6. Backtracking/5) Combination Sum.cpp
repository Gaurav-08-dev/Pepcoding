/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

*/




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