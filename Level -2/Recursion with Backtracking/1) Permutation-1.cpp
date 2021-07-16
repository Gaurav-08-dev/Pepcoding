#include<bits/stdc++.h>
using namespace std;


// ci -> current item ti-> total item
void perm(vector<int> &boxes,int ci,int ti)
{
	if(ci>ti)
	{
		for(auto i:boxes)
		{
			cout<<i;
		}
		cout<<"\n";
		return ;
	}
	for(int box=0;box<boxes.size();box++)
	{
		// if box is empty
		if(boxes[box]==0)
		{
			// place object
			boxes[box]=ci;

			perm(boxes,ci+1,ti);
			
			// unplace
			boxes[box]=0;
		}
	}
}
void solve()
{
	int n,r;
	cin>>n>>r;
	vector<int> boxes(n);
	perm(boxes,1,r);
}
int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}