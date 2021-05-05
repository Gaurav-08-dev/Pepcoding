#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    int a[n][n];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    
    
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            cout<<a[i][j]<<" ";
        }
    }
    
    
}