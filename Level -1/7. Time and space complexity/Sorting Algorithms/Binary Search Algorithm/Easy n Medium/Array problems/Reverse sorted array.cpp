#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={9,8,7,5,4,3,2};

	int s=0,e=(sizeof(a)/sizeof(int)-1);

	int target=2;

	while(s<=e)
	{
		int m=s + (e-s)/2;
		// cout<<m<<" ";

		if(a[m]==target)
		{
			cout<<"Found at: "<<m;
			break;

		}
		else if(a[m]<target)
		{
			e=m-1;
		}
		else
		{
			s=m+1;
		}



	}


}