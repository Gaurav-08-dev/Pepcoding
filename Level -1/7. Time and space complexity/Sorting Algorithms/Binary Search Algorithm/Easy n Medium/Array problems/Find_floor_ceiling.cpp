#include<bits/stdc++.h>
using namespace std;

int find_floor(int a[],int n,int target)
{
	int start=0,end=n-1;
	int mid,ans=-1;

	while(start<=end)
	{
		mid=start+ (end-start)/2;

		if(a[mid]==target)
		{
			ans=a[mid];
			return ans;
		}

		if(target>a[mid])
		{
			ans=a[mid];
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}

	}

	if(ans<0)
	{
		return ans;
	}
	else
	{
		return -1;
	}
	
}

int find_ceil(int a[],int n,int target)
{
	int start=0,end=n-1;
	int mid,ans=-1;

	while(start<=end)
	{
		mid=start + (end-start)/2;

		if(a[mid]==target)
		{
			return mid;
		}

		if(a[mid]>target)
		{
			ans=mid;
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
		// cout<<mid<<endl;
	}

	if(ans<0)
	{
		return -1;
	}
	else
	{
		return ans;
	}
}


int main()
{
	int a[]={10, 13, 14, 20, 50, 80, 80};
	int n=sizeof(a)/sizeof(a[0]);
	int target=80;
	cout<<find_ceil(a,n,target); 
}