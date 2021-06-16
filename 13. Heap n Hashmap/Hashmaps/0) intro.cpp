#include<bits/stdc++.h>
using namespace std;

void solve()
{
	map<int,string> m;

	m[1]="aasas";
	m[6]="fdasfa";
	m[3]="asd";

	m.insert({4,"Gaurav"});

	map<int,string> :: iterator it;

	for(it=m.begin();it!=m.end(); ++it)
	{
		cout<<(*it).first<<" "<< (*it).second<<"\n";
	}

	cout<<"\n\n";
	for(auto &pr: m)
	{
		cout<<pr.first<<" "<<pr.second<<"\n";
	}


	cout<<"\n\n";

	cout<<"Size: "<<m.size();
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}