#include<bits/stdc++.h>
using namespace std;

void solve(int n,int S,int D,int H)
{
	if(n>0)
	{
		// cout<<S<<" "<<D<<" "<<H<<"\n";
		solve(n-1,S,H,D);
		cout<<n<<"["<<S<<"->"<<D<<"]"<<"\n";
		solve(n-1,H,D,S);
	}
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,S,D,H;
	cin>>n>>S>>D>>H;

	solve(n,S,D,H);
}

// 1[10->11]
// 2[10->12]
// 1[11->12]
// 3[10->11]
// 1[12->10]
// 2[12->11]
// 1[10->11]