#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string str;
	cin>>str;
	map<char,int> m;
	for(int i=0;i<str.size();i++)
	{
		// cout<<str[i];
		m[str[i]]++;
	}

	int max=0;
	char ch;
	for(auto pr: m)
	{
		if(pr.second>max)
		{
			max=pr.second;
			ch=pr.first;
		}
	}
	cout<<ch;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}