 // GOLDMAN SACHS



#include<bits/stdc++.h>
using namespace std;


int check_height(int mid,int a1[],int n)
{
	int sum=0;

	for(int i=0;i<n;i++)
	{
		if(a1[i]>mid)
		{
			sum+=(a1[i]-mid);
		}
	}
	// cout<<sum<<endl;

	return sum;
}

int find_height(int a1[],int n, int k)
{
	int start=0,end=*max_element(a1,a1+n);
	// cout<<end<<endl;
	int mid;

	while(start<=end)
	{
		mid=start + (end-start)/2;

		int height=check_height(mid,a1,n);

		if(height==k)
		{
			return mid;
		}
		else if(height>k)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;

		}
	}
	return mid;
}

int main()
{
	int a1[]={81,13,36,65,38,69};

	int n=6,k=47;

	sort(a1,a1+n);

	cout<<find_height(a1,n,k);
}