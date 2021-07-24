#include<bits/stdc++.h>
using namespace std;


void comb1(int i,vector<int> coins,int amtsf,int tamt,string asf)
{
    if(i==coins.size())
    {
        if(amtsf == tamt)
        {
            cout<<asf + '.'<<"\n";
        }
        return;
    }
    
    // yes call
    if(coins[i] + amtsf <= tamt)
    {
        comb1(i,coins,amtsf+coins[i],tamt,asf + to_string(coins[i])+ "-");
    }
    
    // no call
    comb1(i+1,coins,amtsf,tamt, asf);
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> coins;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        coins.push_back(t);
    }
    
    int target;
    cin>>target;
    
    // comb(coins,target,"",-1);
    comb1(0,coins,0,target,"");
}