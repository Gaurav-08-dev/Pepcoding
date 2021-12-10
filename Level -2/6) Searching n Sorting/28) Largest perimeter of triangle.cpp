#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        int mx=0;
        for(int i=nums.size()-3;i>=0;i--)
        {
            if(nums[i] + nums[i+1] > nums[i+2]){
                mx=(nums[i] + nums[i+1] + nums[i+2]);
                break;
            }
        }
        return mx;
        
    }
int main(){
    
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    int ans=solve(arr);
    if(ans==0) cout<<ans;
    else{cout<<ans;}
}