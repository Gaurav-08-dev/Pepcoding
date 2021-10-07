#include<bits/stdc++.h>
using namespace std;


char next_letter(char a[],char key,int start,int n)
{
	int ans;

	while(start<=n)
	{
		int mid=start + (n-start)/2;


		
		if(a[mid]<=key)
		{
			start=mid+1;
		}
		else 
		{
			ans=mid;
			n=mid-1;
		}
	}

	return a[ans];
}

int main()
{
	char a[]={'a','b','c','d','e','f'};
	char key='a';
	int n=(sizeof(a)/sizeof(a[0]))-1;

	cout<<next_letter(a,key,0,n);
}

