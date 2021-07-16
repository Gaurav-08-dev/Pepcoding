#include<bits/stdc++.h>
using namespace std;


// tabulation
int maze_tab(vector<vector<int>> &arr,vector<vector<int>> &dp,int x,int y)
{
    for(int x=arr.size()-1;x>=0;x--)
    {
        for(int y=arr[0].size()-1;y>=0;y--)
        {
            if(x==arr.size()-1 and y==arr[0].size()-1)
            {
                // bottom-right corner
                dp[x][y]=arr[x][y];

            }
            else if(x==arr.size()-1)
            {
                // last row
                dp[x][y]=arr[x][y] + dp[x][y+1];

            }
            else if(y==arr[0].size()-1)
            {
                // last col
                dp[x][y]=arr[x][y] + dp[x+1][y];
            }
            else
            {
                // middle section
                dp[x][y]=arr[x][y] + min(dp[x][y+1],dp[x+1][y]);
            }
        }
    }
    return dp[0][0];
}



// memoization
/*
int maze_mem(vector<vector<int>> &arr,vector<vector<int>> &dp,int x,int y)
{
 if(x==arr.size()-1 and y==arr[0].size()-1)
    {
        return dp[x][y]=arr[x][y];
    }
    if(dp[x][y]!=0)
    {
        return dp[x][y];
    }
    int min_cost=(int)1e9;
    // right 
    if(y+1 < arr[0].size())
    {
        min_cost=min(min_cost,maze_mem(arr,dp,x,y+1));
    }
    // down  

     if(x+1 < arr.size())
    {
        min_cost=min(min_cost,maze_mem(arr,dp,x+1,y));
    }

    return dp[x][y]=min_cost + arr[x][y];   
}*/


// recursion
/*int maze(vector<vector<int>> &arr,int x,int y)
{
    if(x==arr.size()-1 and y==arr[0].size()-1)
    {
        return arr[x][y];
    }
    int min_cost=(int)1e9;

    // right 

    if(y+1 < arr[0].size())
    {
        min_cost=min(min_cost,maze(arr,x,y+1));
    }
    // down  

     if(x+1 < arr.size())
    {
        min_cost=min(min_cost,maze(arr,x+1,y));
    }

    return min_cost + arr[x][y];
}*/


void path(vector<vector<int>> &dp,int x,int y,string psf)
{
    if(x==dp.size()-1 and y==dp[0].size()-1)
    {
        cout<<psf<<"\n";
    }
    else if(x==dp.size()-1)
    {
        path(dp,x,y+1,psf + "R ");
    }
    else if(y==dp[0].size()-1)
    {
        path(dp,x+1,y,psf + "D ");
    }
    else
    {
        if(dp[x][y+1]==dp[x+1][y])
        { 
            //both sides
            path(dp,x+1,y,psf+"D ");
            path(dp,x,y+1,psf + "R ");
        }
        else if(dp[x][y + 1] < dp[x + 1][y]) {
                // right side
                path(dp, x, y + 1, psf + "R ");
            } else {
                // down side
                path(dp, x + 1, y, psf + "D ");
            }

    }
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
    
    cout<<maze_tab(arr,dp,0,0)<<"\n\n";
    path(dp,0,0,"");
}

int main()
{
        #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}