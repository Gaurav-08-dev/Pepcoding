#include<bits/stdc++.h>
using namespace std;

vector<int> stock(vector<int> &arr)
{
	int n=arr.size();
	vector<int> result(n,0);

	stack<int> s;

	s.push(0);
	for(int i=1;i<arr.size();i++)
	{
		while(s.size()>0 and arr[s.top()]<arr[i])
		{
			result[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}

	for(int i=0;i<result.size();i++)
	{
		result[i]=result[i]-i;
		if(result[i]<0)
		{
			result[i]=0;
		}
	}

	return result;
}


void solve()
{
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}	

	vector<int> ans=stock(arr);
	for(auto i: ans)
	{
		cout<<i<<"\n";
	}
}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}


/* stock span -> how many days before today, stock price is higher than today */
/* same as next greater element on left*/