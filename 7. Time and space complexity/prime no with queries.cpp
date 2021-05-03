#include<bits/stdc++.h>
using namespace std;

bool check_prime(int val)
{
	for(int i=2;i<=sqrt(val);i++)
	{
		if(val%i==0)
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	vector<int> primes={10,3,40,7,12};
	for(int i=0;i<primes.size();i++)
	{
		if(check_prime(primes[i])==true)
		{
			cout<<"Prime"<<"\n";
		}
		else
		{
			cout<<"Not prime"<<"\n";
		}
	}	
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
}