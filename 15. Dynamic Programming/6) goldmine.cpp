#include<bits/stdc++.h>
using namespace std;


// tabulation
int helper_tab(vector<vector<int>> &arr,int x,int y,vector<vector<int>> &dp)
{
	int res=0;
	for( y=arr[0].size()-1;y>=0;y--)
	{
		for( x=0;x<arr.size();x++)
		{
			if(y==arr[0].size()-1)
			{
				dp[x][y]=arr[x][y];
			}
			else if(x==0)
			{
				dp[x][y]=max(dp[x][y+1],dp[x+1][y+1])+ arr[x][y];
			}
			else if(x==arr[0].size()-1)
			{
				dp[x][y]=max(dp[x][y+1],dp[x-1][y+1])+ arr[x][y];
			}
			else
			{
				dp[x][y]=max(dp[x-1][y+1],max(dp[x][y+1],dp[x+1][y+1])) + arr[x][y];
			}

			res=max(res,dp[x][y]);
		}
	}

	return res;
}


int helper_tab2(vector<vector<int>> &arr,int x,int y,vector<vector<int>> &dp)
{
	int res=0;
	for(y=arr[0].size()-1;y>=0;y--)
	{
	for(x=0;x<arr.size();x++)
	{
		if(y==arr[0].size()-1)
		{
			 dp[x][y]=arr[x][y]; 
			 res=max(res,dp[x][y]); // to handle single row n column
			 continue;
		}

		if(dp[x][y]!=0)
		{
			return dp[x][y];
		}

		int max_gold=0;

		// top - right 

		if(x-1>=0)
		{
			max_gold=max(max_gold,dp[x-1][y+1]);
		}

		// right
		
			max_gold=max(max_gold,dp[x][y+1]);
		

		// down - right

		if(x+1< arr.size())
		{
			max_gold=max(max_gold,dp[x+1][y+1]);
		}

		dp[x][y]=max_gold + arr[x][y];
		res=max(res,dp[x][y]);
	}

	}

	return res;
}

/* ****************************************************************************************** */
// memoization
int helper_mem(vector<vector<int>> &arr,int x,int y,vector<vector<int>> &dp)
{
	if(y==arr[0].size()-1)
	{
		return dp[x][y]=arr[x][y];
	}

	if(dp[x][y]!=0)
	{
		return dp[x][y];
	}

	int max_gold=0;

	// top - right 

	if(x-1>=0)
	{
		max_gold=max(max_gold,helper_mem(arr,x-1,y+1,dp));
	}

	// right
	
		max_gold=max(max_gold,helper_mem(arr,x,y+1,dp));
	

	// down - right

	if(x+1< arr.size())
	{
		max_gold=max(max_gold,helper_mem(arr,x+1,y+1,dp));
	}

	return dp[x][y]=max_gold + arr[x][y];
}

// recursive
int helper(vector<vector<int>> &arr,int x,int y)
{
	if(y==arr[0].size()-1)
	{
		return arr[x][y];
	}
	int max_gold=0;

	// top - right 

	if(x-1>=0 and y+1<arr[0].size())
	{
		max_gold=max(max_gold,helper(arr,x-1,y+1));
	}

	// right
	if(y+1<arr[0].size())
	{
		max_gold=max(max_gold,helper(arr,x,y+1));
	}

	// down - right

	if(x+1< arr.size() and y+1<arr[0].size())
	{
		max_gold=max(max_gold,helper(arr,x+1,y+1));
	}

	return max_gold + arr[x][y];
}


int goldmine(vector<vector<int>> &arr, vector<vector<int>> &dp)
{
	int maxCost=0;
 
	for(int i=0;i<arr.size();i++)
	{
		maxCost=max(maxCost,helper_mem(arr,i,0,dp));
	}
	return maxCost;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }
 vector<vector<int>> dp(n,vector<int>(m,0));  
    
    cout<<goldmine(arr,dp);
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}