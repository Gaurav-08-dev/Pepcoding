#include <bits/stdc++.h>
using namespace std;

int cs(int n){
    
    if(n==0) return 1;
    
    int count=0;
    for(int i=1;i<=3 ;i++)
    {
        if(n-i>=0)
            count+=cs(n-i);
    }
    
    return count;
}

// Memoization

int cs_mem(int n,vector<int> &dp)
{
    if(n==0) return dp[0]=1;
    
    if(dp[n]!=0) return dp[n];
    
    int count=0;
    
    for(int i=1;i<=3;i++)
    {
        if(n-i>=0)
        {
            count+=cs_mem(n-i,dp);
        }
    }
    
    return dp[n]=count;
}

// Tabulation

int cs_tab(int n,vector<int> &dp)
{
    dp[0]=1;
    
    
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int jump=1;jump<=3;jump++)
        {
            if(i-jump>=0)
            {
                count+=dp[i-jump];
            }
        }
        
        dp[i]=count;
    }
    return dp[n];
}



// converting code from memoization to tabulation

int cs_mem_to_tab(int N,vector<int> &dp)
{
	for(int n=0;n<=N;n++)
	{
		// on base case set it and continue
		if(n==0)
		{
			dp[0]=1;
			continue;
		}

		
		int count=0;

		for(int i=1;i<=3;i++){

			if(n-j>=0)
			{
				count+=dp[n-i];
			}
		}

		dp[n]=count;
	}

	return dp[N];
}


int main(){
    int n;
    cin>>n;
    
    vector<int> dp(n,0);
    cout<<cs_tab(n,dp)<<endl;
}