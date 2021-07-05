#include<bits/stdc++.h>
using namespace std;

   int maxProfit(vector<int>& prices,int fee) {
        
        int pwb=-prices[0],pws=0;
        
        for(int i=1;i<prices.size();i++)
        {
            int npwb=max(pwb,pws-prices[i]);
            int npws=max(pws,pwb+prices[i]-fee);
            
            pwb=npwb;
            pws=npws;
        }
        
        return pws;
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
    
    int fee;
    cin>>fee;
    
    cout<<maxProfit(arr,fee);
}