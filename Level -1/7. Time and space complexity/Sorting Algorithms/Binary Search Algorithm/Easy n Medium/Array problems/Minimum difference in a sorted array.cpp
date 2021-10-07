#include<bits/stdc++.h>
using namespace std;


int find_min(int a[],int start,int end,int key)
{

	while(start<=end)
	{
		int mid=start + (end-start)/2;

		if(a[mid]==key)
		{
			return key;
		}

		else if(key > a[mid])
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	return min(abs(a[start]-key),abs(a[end]-key));

	// apart from difference, index of value with min diff. or value itself can also be returned 

}

int main()
{

	int a[]={1,2,3,4,56};
	int n=sizeof(a)/sizeof(a[0]);
	int key=10;

	cout<<find_min(a,0,n-1,key);

}