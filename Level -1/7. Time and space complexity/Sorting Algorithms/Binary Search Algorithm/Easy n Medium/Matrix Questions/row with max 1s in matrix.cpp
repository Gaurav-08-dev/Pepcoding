#include<bits/stdc++.h>
using namespace std;



int first_index(vector<int> &a,int r)
{
	
	int start=0,end=r;
	int res=-1;

	// for(auto i: a)
	// {
	// 	cout<<i;
	// }

	while(start<=end)
	{
		int mid=start + (end-start)/2;

		if(a[mid]==1)
		{
			res=mid;
			end=mid-1;
		}
		else if(1>a[mid])
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	return res;

}

// Time complexity: O(MlogN)

int result(vector<vector<int>> &a,int row,int column)
{
	int max1=0; //maximum 1s
	int max_index=0; //index with max 1s

	for(int i=0;i<row;i++)
	{
		int f_occur=first_index(a[i],row);
		if(f_occur==-1) continue;
		int count=column-f_occur;

		if(count>max_index)
		{
			max1=count;
			max_index=i;
		}
	}

	return max_index;
}



// Time complexity: O(row+column)

/* int result_2(vector<vector<int>> &a,int row,int column)
{
	int max_index=-1;
	int first_index=first_index(a[0],r);
	
	if(first_index==-1) first_index=column-1;

	int curr_col=column-1;

	for(int i=0;i<row;i++)
	{
		while(curr_col>=0 and a[i][curr_col]==1)
		{
			curr_col-=1;
			max_index=i;
		}
	}

	return max_index;
} */

int main()
{
	vector<vector<int>> a={{0,0,0,1},{1,1,1,1,1}};

// cout<<first_index(a[0],1);

	int ans=result(a,2,4);
	cout<<ans<<endl;


}