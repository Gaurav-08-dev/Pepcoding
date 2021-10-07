#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll n,m,ans;
	cin>>n>>m;

	ll a[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}

	ll start=0,end=*max_element(a,a+n),mid;

	sort(a,a+n);

	while(start<=end)
	{
		mid=start+ (end-start)/2;
		ll sum=0;

		for(ll i=0;i<n;i++)
		{
			if(a[i]>mid)
			{
				sum+=(a[i]-mid);
			}
		}
		if(sum>=m)
		{
			ans=mid;
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	cout<<ans;
}
