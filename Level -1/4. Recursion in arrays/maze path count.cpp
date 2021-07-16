#include<iostream>
#include<vector>

using namespace std;

   
    int countPaths(int m,int n)
    {
    vector<vector<int>>dp (m+1,vector<int>(n+1,-1));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=1;
            }
            else
            {
             dp[i][j]=dp[i-1][j] + dp[i][j-1];   
            }
        }
    }
       return dp[m-1][n-1];
    
    }

void display(vector<vector<int>>& dp){
    for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    
    int m,n; cin >> m >> n;
    cout<<countPaths(m,n,0,0);
    cout<<"\n\n";
    display(dp);
    return 0;
}

