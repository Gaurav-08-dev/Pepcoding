#include<bits/stdc++.h>
using namespace std;



int sum_of_element( int a[],int n)
{
	int sum=0;

	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}

	return sum;
}

int no_of_painters(int a[],int n,int mid)
{
	int count=1;
	int unit=0;

	for(int i=0;i<n;i++)
	{
		unit+=a[i];

		if(unit>mid)
		{
			count++;
			unit=a[i];
		}
	}

	return count;
}

int main()
{

	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		int a[n];

		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		int start=*max_element(a,a+n),end=sum_of_element(a,n);

		while(start<end)
		{
			int mid=start+(end-start)/2;

			if(no_of_painters(a,n,mid)<=k)
			{
				end=mid;
			}
			else
			{
				start=mid+1;
			}
		}
		cout<<start<<endl;
	}

	

}