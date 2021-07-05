#include<bits/stdc++.h>
using namespace std;

   int maxProfit(vector<int>& prices) {
        
        int buy=0,profit=0;
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[buy])
            {
                profit+= prices[i]-prices[buy];
                buy+=1;
            }
            else
            {
                buy+=1;
            }
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
    
    cout<<maxProfit(arr);
}