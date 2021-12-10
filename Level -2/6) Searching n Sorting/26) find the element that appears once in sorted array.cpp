#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int start=0, end=nums.size()-2;
        
        while(start <= end)
        {
            int mid=start + (end-start)/2;
            
            if(nums[mid]==nums[mid^1])
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return nums[start];
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
    int h;
    cin>>h;
    
    cout<<solve(arr,h);
}