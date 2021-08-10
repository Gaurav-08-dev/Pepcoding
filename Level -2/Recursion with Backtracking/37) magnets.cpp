#include<bits/stdc++.h>
using namespace std;

void solution(vector<vector<char>> &arr, )
{
	
}



void solve()
{
	int m,n;
	cin>>m>>n;

	vector<vector<char>> arr;

	for(int i=0;i<m;i++)
	{
		vector<char> t;
		for(int j=0;j<n;j++)
		{
			char temp;
			cin>>temp;
			t.push_back(temp);
		}

		arr.push_back(t);
	}

	vector<int> top,left,right,down;

	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		top.push_back(temp);
	}

	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		down.push_back(temp);
	}

	for(int i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		left.push_back(temp);
	}

	for(int i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		right.push_back(temp);
	}

	solution();
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}