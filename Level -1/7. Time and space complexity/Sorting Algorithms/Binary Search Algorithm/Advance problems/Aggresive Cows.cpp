#include<bits/stdc++.h>

using namespace std;


int main()
{
	int t;

	cin>>t;

	while(t--)
	{
		int n,c;
		cin>>n>>c;

		int stalls[n];

		for(int i=0;i<n;i++)
		{
			cin>>stalls[i];
		}

		sort(stalls,stalls+n);


		int start=0,end=stalls[n-1],mid,best_gap=0;

		while(start<=end)
		{
			mid=start+ (end-start)/2;

			int count=1,left=0;

			for(int i=1;i<n && count<c;i++)
			{
				if(stalls[i]-stalls[left]>=mid)
				{
					left=i;
					count++;
				}
			}

			if(count>=c)
			{
				best_gap=mid;
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		cout<<best_gap<<endl;
	}
}