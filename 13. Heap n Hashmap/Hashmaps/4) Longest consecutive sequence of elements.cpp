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


	//  make a hashmap of presence
	
	unordered_map<int,bool> m;

	for(int i=0;i<n;i++)
	{
		m.insert({a[i],true});
	}

	// make starting point of sequence

	for(int i=0;i<n;i++)
	{
		if(m.find(a[i]-1)!=m.end())
		{
			m.insert({a[i],false});
		}
	}

	// get length and starting point of sequence

	int max_length=0;
	int starting=0;
	
	for(int i=0;i<n;i++)
	{
		if(m[a[i]]==true)
		{
			// key is starting point
			int len=1;
			int st=a[i];

			while(m.find(a[i]+1)!=m.end())
			{
				len++;
				a[i]++;
			}

			if(max_length<len)
			{
				max_length=len;
				starting=st;
			}
			m.insert({a[i],false});

		}
	}

	// print answer

	for(int i=0;i<max_length;i++)
	{
		cout<<starting<<"\n";
		starting++;
	}
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}