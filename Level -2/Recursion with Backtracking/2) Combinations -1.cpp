#include<bits/stdc++.h>
using namespace std;

// cb -> current box, tb -> total box,ti-> total item isf -> item so far
void comb(int cb,int tb,int isf,int ti,string asf)
{
	if(cb > tb)
	{
		if(isf==ti)
		{
			cout<<asf<<"\n";
		}
		return;
	}
	
	// yes call
	if(isf+1 <= ti)
		comb(cb+1,tb,isf+1,ti,asf + "i");

	// no call
	comb(cb+1,tb,isf,ti,asf + "-");
}
void solve()
{
	int n,r;
	cin>>n>>r;
	comb(1,n,0,r,"");
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}