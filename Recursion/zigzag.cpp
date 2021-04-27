#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{

	if(n>0)
	{
		cout<<n<<" ";
		solve(n-1);
		cout<<n<<" ";
		solve(n-1);
		cout<<n<<" ";
	}

}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
	cin>>n;

	solve(n);

}