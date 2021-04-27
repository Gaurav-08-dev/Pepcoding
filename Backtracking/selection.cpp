#include<bits/stdc++.h>
using namespace std;



// void comb1(int n,int bsf string asf)
// {
// 	comb1(n,bsf+1,asf + );
// }

void comb(int c,int r, int n,int m,int bsf,string asf)
{
	if(r==n)
	{
		// if(bsf==2) //only two boxes selected
		// {
		// cout<<asf<<"\n";
		// }
		cout<<asf<<"\n";
		return;
	}


	if(c+1<m)
	{
		// Yes call
		comb(c+1,r,n,m,bsf+1,asf + to_string(r)+to_string(c)+", ");		

		// No call
		comb(c+1,r,n,m,bsf,asf);		
	}
	else
	{
		// yes call
		comb(0,r+1,n,m,bsf+1,asf + to_string(r)+to_string(c)+ ", ");
		// No call
		comb(0,r+1,n,m,bsf,asf);
	}
}



void combq(int c,int r, int n,int m,int bsf,string asf)
{
	if(r==n)
	{
		cout<<asf<<"\n";
		return;
	}
	if(c+1<m)
	{
		// Yes call
		combq(0,r+1,n,m,bsf+1,asf + to_string(r)+to_string(c)+", ");		

		// No call
		combq(c+1,r,n,m,bsf,asf);		
	}
	else
	{
		// yes call
		combq(0,r+1,n,m,bsf+1,asf + to_string(r)+to_string(c)+ ", ");
		// No call
		combq(0,r+1,n,m,bsf,asf);
	}
}

void solve()
{
	int r=2,c=2;
	int n=4;
	combq(0,0,r,c,0,"");
	// comb(n,0,"");
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
}
