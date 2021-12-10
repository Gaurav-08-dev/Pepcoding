#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> &arr,int target,int n)
{
    int lo=0,hi=n-1;
    
    while(lo<hi){
        int difference=arr[hi]-arr[lo];
        
        if(difference == target)
        {
            cout<<arr[lo]<<" "<<arr[hi];
            return;
        }
        else if(difference > target)
        {
            lo++;
        }
        else
        {
            hi--;
        }
    }
    
    cout<<-1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int target;
    cin>>target;
    
    sort(arr.begin(),arr.end());
    solve(arr,target,n);
}