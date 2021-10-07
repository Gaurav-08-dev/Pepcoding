#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1,2,3,4,54};

	int size=sizeof(a)/sizeof(a[0]);
	int target=54;

	if(size<=1)
	{
		if(target==a[0])
		{
			cout<<"Found";
		}
		else
		{
			cout<<"Not found";
		}

	}
	else if(a[0]<a[1]) 
	{
		ascen(a);
	}
	else
	{
		descen(a);
	}

}