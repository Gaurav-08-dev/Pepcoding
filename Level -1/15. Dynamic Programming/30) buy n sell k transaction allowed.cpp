
#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int> &arr,int k) //O(n^3)
{
	vector<vector<int>> dp(k+1,vector<int>(arr.size()));

	for(int t=1;t<=k;t++)
	{
		for(int d=1;d<arr.size();d++) //days
		{
			// dp[t][d]=dp[t][d-1];

			int max1=dp[t][d-1];
			for(int pd=0;pd<d;pd++)
			{
				int profitTillTm1=dp[t-1][pd]; // profit till t-1 
				int ptth=arr[d]- arr[pd];// profit of t transaction

				if(profitTillTm1 + ptth > max1)
				{
					max1=profitTillTm1 + ptth;
				}
			}

			dp[t][d]=max1;
		}
	}

	return dp[k][arr.size()-1];
}


/* **************************************************** */
int maxProfit_optimized(vector<int> &arr,int k) //O(n^2)
{
	vector<vector<int>> dp(k+1,vector<int>(arr.size()));

	for(int t=1;t<=k;t++)
	{
		int max=INT_MIN;
		for(int d=1;d<arr.size();d++) //days
		{
			if(dp[t-1][d-1]-arr[d-1] > max)
			{
				max=dp[t-1][d-1]-arr[d-1];	
			}
			if(arr[d] + max > dp[t][d-1])
			{
				dp[t][d]=max + arr[d];
			}
			else
			{
				dp[t][d]=dp[t][d-1];
			}
		}
	}
	return dp[k][arr.size()-1];
}

int main(){

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

    int k;
    cin>>k;
    if(k>n)
    {k=n/2;}

    cout<< maxProfit_optimized(arr,k);
}