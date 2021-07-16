#include<bits/stdc++.h>
using namespace std;

// recursion
int countEncoding_rec(string str,int index)
{
    if(index==str.size()) return 1;
    
    if(str.at(index)=='0') return 0;
    
    int count=0;
    
    int n1=str.at(index)-'0';
    count+=countEncoding_rec(str,index+1);
    
    if(index+1< str.size())
    {
        int n=str.at(index+1) - '0';
        int n2=n1 * 10 + n;
        if(n2<=26)
        {
            count+=countEncoding_rec(str,index+2);
        }
    }
    
    return count;
}

// memoization
int countEncoding_mem(string str,int index,vector<int> &dp)
{
    if(index==str.size()) return dp[index]=1;
    
    if(str.at(index)=='0') return dp[index]=0;
    
    
    if(dp[index]!=0) return dp[index];
    int count=0;
    
    int n1=str.at(index)-'0';
    count+=countEncoding_mem(str,index+1,dp);
    
    if(index+1< str.size())
    {
        int n=str.at(index+1) - '0';
        int n2=n1 * 10 + n;
        if(n2<=26)
        {
            count+=countEncoding_mem(str,index+2,dp);
        }
    }
    
    return dp[index]=count;
}

// tabulation
int countEncoding_tab(string str)
{
	vector<int> dp(str.size()+1);

    for(int index=str.size();index>=0;index--)
    {
	  	if(index==str.size()) {dp[index]=1; continue;}
	    
	    if(str.at(index)=='0') {dp[index]=0; continue;}
	    
	    int count=0;
	    
	    int n1=str.at(index)-'0';
	    count+=dp[index+1];
	    
	    if(index+1< str.size())
	    {
	        int n=str.at(index+1) - '0';
	        int n2=n1 * 10 + n;
	        if(n2<=26)
	        {
	            count+=dp[index+2];
	        }
	    }
	    dp[index]=count;
    }
    return dp[0];
}


int main()
{
    string str;
    cin>>str;
    vector<int> dp(str.size()+1);
    cout<<countEncoding_tab(str);
}