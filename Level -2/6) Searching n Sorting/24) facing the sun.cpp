#include<bits/stdc++.h>
using namespace std;



int solve(vector<int> &ans){
    
    int mx=ans[0];
    int count=1;
    
    for(int i=1;i<ans.size();i++){
        if(ans[i] > mx){
            mx=ans[i];
            count++;
        }
    }
    return count;
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
    
    cout<<solve(arr);
}