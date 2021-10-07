#include<bits/stdc++.h>
using namespace std;


float square_root(int n,int p)
{
	int start=0, end=n;

	float ans,mid;

	while(start<=end)
	{
		int mid=start + (end-start)/2;

		if(mid*mid==n)
		{
			return mid;
		}

		if(mid*mid>n)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
			ans=mid;
		} 
	}

	/* fraction part*/

	float increment=0.1;

	 // p -> precision value

	for(int i=0;i<p;i++)
	{
		while(ans*ans<=n)
		{
			ans+=increment;
		}
		ans=ans-increment;
		increment/=10;
	}

	return ans;
}





int main()
{
	int n=5;

	cout<<square_root(n,3);

}