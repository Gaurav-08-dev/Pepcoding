#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr){
    
    int sum=0;
    int sim1=0;
    
    for(int i=0;i<arr.size();i++){
        sim1+=arr[i]*i;
        sum+=arr[i];
    }
    
    int res=sim1;
    
    int n=arr.size();
    for(int i=1;i<n;i++){
        int si = sim1 + sum - n*arr[n-i];
        res=max(si,res);
        sim1=si;
    }
    return res;
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