#include<bits/stdc++.h>
using namespace std;


vector<int> rsi(vector<int> &arr)
{
	int n=arr.size();
	vector<int> ans(n,n);
	stack<int> s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(s.size()>0 and arr[s.top()]>arr[i])
		{
			ans[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	return ans;
}

vector<int> lsi(vector<int> &arr)
{
	vector<int> result(arr.size(),-1);
	stack<int> s;
	s.push(arr.size()-1);

	for(int i=arr.size()-2;i>=0;i--)
	{
		while(s.size()>0 and arr[s.top()]>arr[i])
		{
			result[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	return result;
}

int lah(vector<int> &arr)
{
	int n=arr.size();

	vector<int> lsi1=lsi(arr);
	vector<int> rsi1=rsi(arr);

	int max1=INT_MIN;
	int area=0;
	for(int i=0;i<arr.size();i++)
	{
		area=(rsi1[i]-lsi1[i]-1)*arr[i];
		max1=max(area,max1);
	}

	return max1;

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

	cout<<lah(arr)<<"\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}