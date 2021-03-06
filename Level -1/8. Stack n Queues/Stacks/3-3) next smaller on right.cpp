#include<bits/stdc++.h>
using namespace std;


vector<int> smaller_right(vector<int> &arr)
{
	int n=arr.size();
	vector<int> ans(n,-1);
	stack<int> s;
	s.push(0);

	for(int i=1;i<n;i++)
	{
		while(s.size()>0 and arr[s.top()]>arr[i])
		{
			ans[s.top()]=arr[i];
			s.pop();
		}
		s.push(i);
	}
	return ans;
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

	vector<int> ans =smaller_right(arr);

	for(auto i: ans)
	{
		cout<<i<<"\n";
	}
}
	

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}