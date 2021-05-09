#include<bits/stdc++.h>
using namespace std;



vector<int> greater_right_2(vector<int> &arr)
{
	vector<int> result(arr.size(),-1);
	stack<int> s;
	s.push(0);

	for(int i=1;i<arr.size();i++)
	{
		while(s.size()>0 and arr[s.top()]<arr[i])
		{
			
			result[s.top()]=arr[i];
			s.pop();
		}

		s.push(i);
	}

	return result;
}



vector<int> greater_right(vector<int> &arr)
{
	vector<int> a;
	stack<int> s;

	s.push(arr[arr.size()-1]);
	a.push_back(-1);
	for(int i=arr.size()-2;i>=0;i--)
	{
		while(s.size()>0 and arr[i]>=s.top())
		{
			s.pop();
		}

		if(s.size()==0)
		{
			a.push_back(-1);
		}
		else
		{
			a.push_back(s.top());
		}
		s.push(arr[i]);
	}

	return a;
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

	vector<int> ans=greater_right_2(arr);
	for(auto  i=ans.rbegin(); i!=ans.rend();++i)
	{
		cout<<*i<<"\n";
	}
	cout<<"\n";
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}