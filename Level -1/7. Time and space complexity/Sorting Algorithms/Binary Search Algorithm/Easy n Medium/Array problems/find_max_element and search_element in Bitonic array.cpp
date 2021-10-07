#include<bits/stdc++.h>

using namespace std;



// Bitonic--> which is increasing and decreasing monotonically

// Finding peak element concept will be used

// 1,2,3,6,5,4,0


int asc(vector<int> &a,int start,int end,int key)
{
	while(start<=end)
	{
		int mid=start + (end-start)/2;

		if(a[mid]==key)
		{
			return mid;
		}

		else if(a[mid]>key)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}

	return -1;
}


int dsc(vector<int> &a,int start,int end,int key)
{
	while(start<=end)
	{
		int mid=start + (end-start)/2;

		if(a[mid]==key)
		{
			return mid;
		}

		else if(a[mid]>key)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	return -1;
}

int find_max(vector<int>& a)
{
	int n=a.size();

	int start=0,end=n-1;

	while(start<=end)
	{
		int mid=start + (end-start)/2;

		if(mid>0 and mid<n-1)
		{
			if(a[mid]>a[mid+1] and a[mid]>a[mid-1])
			{
				// return a[mid];

				return mid; //for searching
			}
			else if(a[mid]<a[mid+1])
			{
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
	}
	return -1;
}

int search(vector<int> &a,int key)
{
	int anchor=find_max(a);
	// cout<<anchor;

	
	int res=asc(a,0,anchor-1,key);
	int res2= dsc(a,anchor,a.size()-1,key);

	return max(res,res2);
	
}

int main()
{
	vector<int> a={1,2,8,16,5,4};

	// cout<<find_max(a);
	cout<<search(a,4);

}