// How many times a sorted array is rotated clockwise

// Input: Given an sorted array,which is rotated


// procedure: 

// 1) find index of the minimum element
//    -> minimum element is smaller then both of its neighbours


// for anticlockwise rotation
//  next -> (mid+1)%n
// prev-> (mid+n-1)%n






//  how to decide where to move:-
//  move to unsorted array





// corner cases:
// if(a[start] < a[end])   -> it is already sorted



#include<bits/stdc++.h>
using namespace std;






// recursive method
int countrotation_clockwise(int a[],int start,int end)
{
	if(end<start)
	{
		return 0;
	}

	if(end==start)
	{
		return start;
	}

	int mid=start +(end-start)/2;

	if(mid<end && a[mid+1]>a[mid])
	{
		return mid+1;
	}
	if(mid>start && a[mid-1]>a[mid])
	{
		return mid;
	}

	if(a[start]>a[end])
	{
		return countrotation_clockwise(a,start,mid-1);
	}

	return countrotation_clockwise(a,mid+1,end);
}


// Iterative
int countrotation_clockwise(int a[],int n)
{
	int start=0,end=n-1,mid;

	if(start==end)
	{
		return 0;
	}

	while(a[start]>a[end])
	{
		mid=start +(end-start)/2;

		if(a[mid]>a[end])
		{
			start=mid+1;
		}
		else
		{
			end=mid;
		}

	}
	return start;

}


// array is rotated anti clockwise
int countrotation_anticlockwise(int a[],int n)
{
	int start=0,end=n-1,mid;

	while(start<=end)
	{

		if(a[start]<=a[end])
		{
			return start;
		}

		int mid=start + (end-start)/2;

		int next=(mid+1)%n;
		int prev=(mid-1+n)%n;

		if(a[mid]<=a[next] && a[mid]<=a[prev])
		{
			return mid;
		}

		else if(a[mid]<=a[end])
		{
			end=mid-1;
		}

		else if(a[mid]>=a[start])
		{
			start=mid+1;
		}
	}

	return -1;

}




// array rotation count and smallest no. in rotated array with duplicates

int count_duplicates(int a[],int n)
{
	int start=0,end=n-1;

	if(start==end)
	{
		return 0;
	}

	while(start<=end)
	{

		while(nums[start]==nums[end] and start!=end)
		{
			start++;
		}

		if(nums[start]==nums[end])
		{
			return nums[start];
		}

		mid=start + (end-start)/2;

		if(nums[end]>=nums[start])
		{
			start=mid+1;
		}
		else
		{
			end=mid;
		}
	}

	return -1;
}

int main()
{

	int a[]={14,15,11,12,13};
	int start=0,end=sizeof(a)/sizeof(int)-1;
	int flag=0;
	int mid;

	// cout<<countrotation_clockwise(a,end+1);
	// cout<<countrotation(a,start,end);
	// cout<<countrotation_anticlockwise(a,end+1);

	cout<<count_duplicates(a,end+1);
}