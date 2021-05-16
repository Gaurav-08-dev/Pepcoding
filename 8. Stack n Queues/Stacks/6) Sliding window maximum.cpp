#include<bits/stdc++.h>
using namespace std;

vector<int> gri(vector<int> &arr)
{
	int n=arr.size();
	vector<int> res(n,n);
	stack<int> s;

	s.push(0);

	for(int i=1;i<n;i++)
	{
		while(s.size()>0 and arr[s.top()]<arr[i])
		{
			res[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}

	return res;
}


void sliding_maximum(vector<int> &arr,int k)
{
	vector<int> m=gri(arr);

	int j=0;

	for(int i=0;i<=arr.size()-k;i++)
	{
		if(i>j)
		{
			j=i;
		}
		while(i+k>m[j])
		{
			j=m[j];
		}
		cout<<arr[j]<<" ";
	}

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

	int k; cin>>k;

	sliding_maximum(arr,k);

}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}