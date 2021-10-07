// array will always be sorted

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={11,12,13,14,15};
	int target=11;
	int start=0,end=sizeof(a)/sizeof(int);
	int flag=0;
	int mid;
	int res=-1;


	while(start<=end)
	{
		mid= start+ (end-start)/2; // to prevent overflow

		if(target==a[mid])
		{
			res=mid;
			end=mid-1;
		}
		else if(target>a[mid])
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	// if(flag==0)
	// {
	// 	cout<<"Not found";
	// }
	// else
	// {
	// 	cout<<"found at "<<mid;
	// }
}