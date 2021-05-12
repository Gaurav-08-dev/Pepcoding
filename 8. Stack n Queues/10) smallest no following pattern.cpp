#include<bits/stdc++.h>
using namespace std;

void smallest(string pattern)
{
	int count=1;
	stack<string> s;
	for(int i=0;i<pattern.size();i++)
	{
		s.push(to_string(count));
		count++;
		if(pattern[i]=='i')
		{
			while(s.size()>0)
			{
				cout<<s.top();
				s.pop();
			}
		}
	}

	s.push(to_string(count));
	while(s.size()>0)
	{
		cout<<s.top();
		s.pop();
	}

}
void solve()
{
	string pattern;
	cin>>pattern;

	smallest(pattern);
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}