#include<bits/stdc++.h>
using namespace std;


// ci -> for level
// ti -> for base case
// lb -> last_box -> make a loop in sorted index in previous level

void comb(vector<int> &boxes,int ci,int ti,int lb)
{
	if(ci > ti){

		for(int i:boxes){

			if(i==0) 
				cout<<"-";
			else
				cout<<"i";
		}
		cout<<"\n";
		return;
	}
	
	for(int b=lb+1;b<boxes.size();b++)
	{
		// place ci item bth box
		boxes[b]=ci;

		comb(boxes,ci+1,ti,b);

		// unplace
		boxes[b]=0;

	}
}

void solve()
{
	int n,r;
	cin>>n>>r;
	vector<int> boxes(n);
	comb(boxes,1,r,-1);	
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}