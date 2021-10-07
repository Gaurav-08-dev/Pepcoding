#include<bits/stdc++.h>
using namespace std;




int first_occurence(int a[],int start,int end,int target)
{
	int res=-1;
	int mid;

	while(start<=end)
	{
		mid=start + ((end-start)/2);
		if(a[mid]==target)
		{
			res=mid;
			end=mid-1;
		}
		else if(target<a[mid])
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	// cout<<"first_occurence: "<<res<<endl;
	return res;

}



int last_occurence(int a[],int start,int end,int target)
{
	int res=-1;
	int mid;

	while(start<=end)
	{
		mid=start+ (end-start)/2;
		if(a[mid]==target)
		{
			res=mid;
			start=mid+1;
		}
		else if(target<a[mid])
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	// cout<<"last_occurence: "<<res<<endl;

	return res;
}

int main()
{
	int a[]={11,12,12,12,12,13,14,15};
	int target=12;
	int size=sizeof(a)/sizeof(int);
	int start=0,end=size-1;
	int flag=0;
	

	// cout<<start<<" "<<end<<" "<<mid;


	int first=first_occurence(a,start,end,target);
	int last=last_occurence(a,start,end,target);

	cout<<last-first+1<<endl;


}