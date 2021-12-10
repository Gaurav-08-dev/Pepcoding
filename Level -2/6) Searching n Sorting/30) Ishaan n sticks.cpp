#include<bits/stdc++.h>
using namespace std;


pair<int,int> solve(vector<int> &nums){
    
    unordered_map<int,int> m;
    
    for(int i:nums){
        m[i]++;
    }
    
    int count=0,maxArea=0;
    
    for(auto it:m){
        
        int side=it.first,sideCount=it.second;
        count=0;
    //  cout<<side<<" ***"<<sideCount<<"\n";   
        if(sideCount/4 > 0){
            maxArea=max(side*side,maxArea);
            count+=(sideCount/4);
            // cout<<count<<"\n";
        }
    }
    
    return {maxArea,count};
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
    
    pair<int,int> p=solve(arr);
    cout<<p.first<<" "<<p.second;
}