#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}


	int n2;
	cin>>n2;

	int a2[n2];
	for(int i=0;i<n2;i++)
	{
		cin>>a2[i];
	}

	unordered_map<int,int> m;

	for(int i=0;i<n;i++)
	{
		m[a[i]]++;
	}

	for(int i=0;i<n2;i++)
	{
		auto it=m.find(a2[i]);

		if(it!=m.end() and it->second>0)
		{
			cout<<a2[i]<<"\n";
			it->second--;
		}
	}



}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}