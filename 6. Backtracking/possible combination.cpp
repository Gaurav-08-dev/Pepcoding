#include<bits/stdc++.h>
using namespace std;

int n=2,m=2;

void select_2_boxes(int cb,int tb,int bsf,string asf)
{

	if(cb==tb)
	{
		if(bsf==2) 
		{
			cout<<asf<<"\n";
		}
		return;
	}

	// yes
	select_2_boxes(cb+1,tb,bsf+1,asf + "b" + to_string(cb) + " ");
	// no
	select_2_boxes(cb+1,tb,bsf,asf);
}

void solve_matrix(int cr,int cc,int n,int m,int bsf,string asf)
{

	if(cr==n)
	{
		cout<<asf<<"\n";
		return;
	}

	// yes

	if(cc+1<m)
	{
		solve_matrix(cr,cc+1,n,m,bsf,asf + "b" + to_string(cr) + to_string(cc) + " ");
	}
	else
	{
		solve_matrix(cr+1,0,n,m,bsf,asf + "b" + to_string(cr) + to_string(cc) + " ");		
	}
	// no

	if(cc+1<m)
	{
		solve_matrix(cr,cc+1,n,m,bsf,asf);
	}
	else
	{
		solve_matrix(cr+1,0,n,m,bsf,asf);
	}

}

void select_single_box(int cr,int cc, int n, int m, int bsf, string asf)
{
	if(cr==n)
	{
		if(bsf==2)
		{
			cout<<asf<<"\n";
		}
		return;
		// cout<<asf<<"\n";

	}

	if(cc+1<m) //next column is valid
	{
		select_single_box(cr+1,0,n,m,bsf+1,asf + "b" + to_string(cr) + to_string(cc) + " ");
		select_single_box(cr,cc+1,n,m,bsf,asf);	
	}
	else //next column is invalid
	{
		select_single_box(cr+1,0,n,m,bsf+1,asf + "b" + to_string(cr) + to_string(cc) + " ");	
		select_single_box(cr+1,0,n,m,bsf,asf);
	}
}

void solve(int cb,int tb,string asf)
{

	if(cb==tb)
	{
		cout<<asf<<"\n";
		return;
	}

	// yes
	solve(cb+1,tb,asf + "b" + to_string(cb) + " ");
	// no
	solve(cb+1,tb,asf);

}
int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    // solve(0,4,0,"");
    // select_2_boxes(0,4,0,"");
    // solve_matrix(0,0,n,m,0,"");
    select_single_box(0,0,n,m,0,"");
}