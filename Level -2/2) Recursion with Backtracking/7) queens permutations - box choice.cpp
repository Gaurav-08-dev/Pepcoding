#include<bits/stdc++.h>
using namespace std;

void perm(vector<int> &queen_places,int col,int row,string asf,int tq,int qpsf)
{
	if(row==tq)
	{
		if(qpsf==tq)
		{
			cout<<asf<<"\n";
			cout<<"\n";
		}
		return;
	}
	// yes call
	for(int q=0;q<queen_places.size();q++)
	{
		if(queen_places[q]==0)
		{
			queen_places[q]=1;
			if(col+1 < tq)
				{perm(queen_places,col+1,row,asf+"q"+to_string(q+1)+"\t",tq,qpsf+1);}
			else
				{perm(queen_places,0,row+1,asf+"q"+to_string(q+1)+"\n",tq,qpsf+1);}

			queen_places[q]=0;	
		}
	}

	// no call
	if(col+1 < tq)
			perm(queen_places,col+1,row,asf+"-\t",tq,qpsf);
		else
			perm(queen_places,0,row+1,asf+ "-\n",tq,qpsf);
}



void solve()
{
	int n;
	cin>>n;
	vector<int> queen_places(n);
	perm(queen_places,0,0,"",n,0);

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}