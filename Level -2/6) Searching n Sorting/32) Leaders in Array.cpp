 #include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums){
    
    vector<int> ans;
    
    int m=INT_MIN;
    for(int i=nums.size()-1;i>=0;i--){
        
        if(nums[i] >= m){
            ans.push_back(nums[i]);
            m=nums[i];
        }
    }
    
    
     
     for(int i=ans.size()-1;i>=0;i--){
         cout<<ans[i]<<" ";
     }
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
    
    
    solve(arr);
}