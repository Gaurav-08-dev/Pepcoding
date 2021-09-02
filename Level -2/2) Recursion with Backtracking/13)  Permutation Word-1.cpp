#include<bits/stdc++.h>
using namespace std;

void perm(int cb, int tb, string str,string asf,map <char,int> &m)
{
	if(cb > tb)
	{
		cout<<asf<<"\n";
		return;
	}	

	for(auto i:m)
	{
		if(m[i.first]>0) // check if frequency of character is > 0
		{
			m[i.first]-=1;
			perm(cb+1,tb,str,asf + i.first,m);
			m[i.first]+=1;
		}
	}
}

void solve()
{
	string str;
	cin>>str;
	map<char,int> m; //frequency map to map count of each unique character
	for(int i=0;i<str.size();i++)
	{
		if(m.find(str[i]) == m.end())
		{
			m.insert({str[i],1});
		}
		else
		{
			m[str[i]]++;
		}
	}
	perm(1,str.size(),str,"",m);	

}

int main(){

//   #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
    solve();

}