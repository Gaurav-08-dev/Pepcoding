#include<bits/stdc++.h>
using namespace std;



int search_in_nearly_sorted(int a[],int n,int target)
{

	int start=0,end=n-1;

while(start<=end)
{
	int mid=start + (end-start)/2;

	if(a[mid]==target)
	{
		return mid;
	}
	if(mid-1>=start && a[mid-1]==target)
	{
		return mid-1;
	}
	if(mid+1<=end && a[mid+1]==target)
	{
		return mid+1;
	}

	if(target>a[mid])
	{
		start=mid+2;	

	}
	else
	{
		end=mid-2;

	}
}

	return -1;

}

int main()
{
	int a[]={10, 3, 40, 20, 50, 80, 70};
	int n=sizeof(a)/sizeof(a[0]);
	int target=70;
	cout<<search_in_nearly_sorted(a,n,target);
}
