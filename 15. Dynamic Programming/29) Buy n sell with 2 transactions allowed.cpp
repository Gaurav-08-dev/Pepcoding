#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        
        int mpist=0; // max profit if sold today
        int leastsf=prices[0]; // least so far
        vector<int> mpsf(prices.size()); // max profit so far
        
        
        for(int i=1;i<prices.size();i++)
        {
            // maintaining least so far
            if(prices[i]<leastsf)
            {
                leastsf=prices[i];
            }
            
            mpist=prices[i] - leastsf;
            
            // maintaining profit so far
            if(mpist > mpsf[i-1])
            {
                mpsf[i]=mpist;
            }
            else
            {
                mpsf[i]=mpsf[i-1];
            }
        }
          
  
        int mpibt=0; // max profit if bought today
        int maxat=prices[prices.size()-1]; // max after today
        vector<int> dpmpat(prices.size(),0); // max profit today or after today        
        for(int i=prices.size()-2;i>=0;i--)
        {
            if(prices[i] > maxat)
            {
                maxat=prices[i];
            }

            
            mpibt=maxat - prices[i];
        
            if(mpibt > dpmpat[i+1])
            {
                dpmpat[i]=mpibt;
            }
            else
            {
                dpmpat[i]=dpmpat[i+1];
            }
        }

        
        int op=0; // overall profit
        for(int i=0;i<prices.size();i++)
        {
            if(mpsf[i] + dpmpat[i] > op)
            {
                op=mpsf[i] + dpmpat[i];
            }
        }
        
        return op;
        
    }


int main()
{
       #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    int n;
    cin>>n;
    
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }

    cout<< maxProfit(arr);
}



