#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr){
    
    map<int,int> m;
    for(int i: arr){
        int fq= m.find(i)==m.end() ? 0: m[i];
        m[i]=fq+1;
    }
    
    int pairCount=0;
    
    for(auto x: m){
        int freq=x.second;
        pairCount+= freq * (freq-1) /2;
    }
    return pairCount;
    
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