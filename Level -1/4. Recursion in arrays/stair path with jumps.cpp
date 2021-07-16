#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int* jumps,int n)
{
	if(n==0)
	{
		vector<string> bres;
		bres.push_back("");	
		return bres;
	}

	
	vector<string> ans;

		for(int j=0;j<jumps[n] and n-j>=0 ;j++)
		{
			vector<string> rres=solve(jumps,n-j);
			for(auto s: rres)
			{
				ans.push_back(to_string(j)+s);
			}
		}

	return ans;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    solve();

}