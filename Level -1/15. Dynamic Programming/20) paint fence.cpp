#include<bits/stdc++.h>
using namespace std;

int paintFence(int n,int k)
{
    int s=0,d=k;
    
    for(int i=1;i<n;i++)
    {
        int ns=d;
        int nd=(s + d) * (k-1);
        
        s=ns;
        d=nd;
    }
    
    return s+d;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    cout<<paintFence(n,k);
}


int main()
{
    solve();
}