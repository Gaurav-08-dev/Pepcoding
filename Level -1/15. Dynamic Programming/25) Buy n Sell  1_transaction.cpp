#include<bits/stdc++.h>
using namespace std;



int profit(vector<int> &arr)
{
    int profit=0;
    int price=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        profit=max(profit,arr[i]-price);
        price=min(price,arr[i]);
    }
    
    return profit;
}



int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    
    cout<<profit(arr);
}