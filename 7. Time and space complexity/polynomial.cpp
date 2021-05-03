#include<bits/stdc++.h>
using namespace std;

void solve(int x,int n)
{
	int xval=x,sum=0;

	for(int i=n;i>=1;i--)
	{
		sum+=i*xval;
		xval*=x;


	}	

	cout<<sum;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve(2,5);

}