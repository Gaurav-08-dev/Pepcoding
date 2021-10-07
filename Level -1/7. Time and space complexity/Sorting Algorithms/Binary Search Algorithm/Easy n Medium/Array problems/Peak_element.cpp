#include<bits/stdc++.h>
using namespace std;


// a peak element should be greater then both of its neighbours


// if mid+1 > mid -> move to right side
// if mid-1 > mid -> move to left side



int find_peak(int a[])
{

	int n=sizeof(a)/sizeof(a[0]);

	int start=0,end=n-1;

	while(start<=end)
	{
		int mid=start + (end-start)/2;

		if(mid>0 and mid<n-1)
		{
			if(a[mid]>a[mid-1] and a[mid]>a[mid+1])
			{
				return mid;
			}

			else if(a[mid+1]>a[mid])
			{
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
		else if(mid==0)  //edge case
		{
			if(a[0]>a[1])
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if(mid==n-1) //edge case
		{
			if(a[n-1]>a[n-2])
			{
				return n-1;
			}
			else
			{
				return n-2;
			}
		}
	}

	return -1;

}
