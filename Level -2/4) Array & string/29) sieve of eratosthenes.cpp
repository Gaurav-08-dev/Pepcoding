#include<bits/stdc++.h>
using namespace std;

vector<bool> solve(int n)
{

    int counter=2;
    vector<bool> isprime(n+1,true);
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(isprime[i]==true)
        {
            while(i*counter<=n)
            {
                if(isprime[i*counter]==true)
                    isprime[i*counter]=false;
                counter++;
            }
            counter=2;
        }
    }
    
    return isprime;
    
}
int main()
{
    int n;
    cin>>n;
    vector<bool> ans=solve(n);
    
    for(int i=2;i<ans.size();i++){
        if(ans[i])
        {
            cout<<i<<" ";
        }
    }
}