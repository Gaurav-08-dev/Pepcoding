#include<bits/stdc++.h>
using namespace std;



bool isvalid(vector<int>& a,int n,int k,int mid)
{
	int sum=0;
	int s=1;

	for(int i=0;i<a.size();++i)
	{
		sum+=a[i];
		if(sum>mid)
		{
			s+=1;
			sum=a[i];
		}

		if(s>k)
		{
			return false;
		}
	}
	return true;
}

int sum(vector<int> &a) //find sum of array
{
	int res=0;
	for(int i=0;i<a.size();++i)
	{
		res+=a[i];
	}

	return res;
}

int find(vector<int>&a, int n,int k)
{
	int start=*max_element(a.begin(),a.end());
	int end=sum(a);
	int res=-1;
	while(start<=end)
	{
		int mid=start+ (end-start)/2;

		if(isvalid(a,n,k,mid)==true)
		{
			res=mid;
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	return res;
}

int main()
{
	vector<int> a={10,20,30,40};

	int n=a.size();

	int k=2;

	cout<<find(a,n,k);

}