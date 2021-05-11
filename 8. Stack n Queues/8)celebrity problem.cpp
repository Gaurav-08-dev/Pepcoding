#include<bits/stdc++.h>
using namespace std;

void candidate(vector<vector<int>> &arr)
{
	stack<int> s;

	for(int i=0;i<arr.size();i++)
	{
		s.push(i);
	}

	// elimination
	while(s.size()>1)
	{
		int i=s.top();
		s.pop();
		int j=s.top();
		s.pop();

		if(arr[i][j]==1)
		{
			// i is not celebrity
			s.push(j);
		}
		else
		{
			// j is not celebrity
			s.push(i);
		}

	}

	int cand=s.top();
	s.pop();

	for(int i=0;i<arr[0].size();i++)
	{
		if(arr[cand][i]==1)
		{
			cout<<"none"<<"\n";
			return ;
		}
	}


	for(int i=0;i<arr.size();i++)
	{
		if(i!=cand and arr[i][cand]==1)
		{
			cout<<"none"<<"\n";
			return ;
		}
	}

	cout<<cand<<"\n";
}


void solve()
{
	int n;
	cin>>n;

	vector<vector<int>> arr;

	for(int i=0;i<n;i++)
	{
		vector<int> temp;
			string c;
			getline(cin,c);
		for(int j=0;j<n;j++)
		{
			temp.push_back(c[j]-'0');
		}
		arr.push_back(temp);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j];
		}
		cout<<"\n";
	}

	candidate(arr);


}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}