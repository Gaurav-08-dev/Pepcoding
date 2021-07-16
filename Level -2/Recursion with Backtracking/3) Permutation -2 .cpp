#include<bits/stdc++.h>
using namespace std;


void perm(int cb,int tb,vector<int> &items,int isf,int ti,string asf)
{

	if(cb > tb)
	{
		if(isf == ti)
		{
			cout<<asf<<"\n";
		}
		return;
	}
	// yes call
	for(int i=0;i<items.size();i++)
	{
		if(items[i]==0)
		{
			// mark  item
			items[i]=1;
			perm(cb+1,tb,items,isf+1,ti,asf+ to_string(i+1));
			// unmark item
			items[i]=0;
		}
	}

	// no call
	perm(cb+1,tb,items,isf,ti,asf+ to_string(0));

}

void solve()
{
	int n,r;
	cin>>n>>r;
	vector<int> items(r);
	perm(1,n,items,0,r,"");	
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}