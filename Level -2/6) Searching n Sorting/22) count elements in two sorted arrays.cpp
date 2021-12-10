#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> &arr1, vector<int> &arr2, 
                                 int m, int n)
    {
    //Your code goes here
    vector<int> ans;
    sort(arr2.begin(),arr2.end());
    
    for(int i=0;i<m;i++){
        int count=0;
        
        int low=0,high=n-1;
        while(low<=high){
            int mid= low + (high-low)/2;
            
            if(arr2[mid]<=arr1[i]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        count+=low;
        ans.push_back(count);
    }
    return ans;
    }
int main(){
    
    int m;
    cin>>m;
    vector<int> arr1;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }
    int n;
    cin>>n;
    vector<int> arr2;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }
    
    vector<int> ans=solve(arr1,arr2,m,n);
    for(int i: ans){
        cout<<i<<" ";
    }
}