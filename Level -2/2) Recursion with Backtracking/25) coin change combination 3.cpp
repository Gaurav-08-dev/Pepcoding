#include<bits/stdc++.h>
using namespace std;

void comb1(vector<int> coins,int amtsf,int tamt,string asf,vector<bool> &used)
{
    if(amtsf == tamt)
    {
        cout<<asf+'.'<<"\n";
        return;
    }
    for(int i=0;i<coins.size();i++)
    {
        if(used[i]==false and coins[i] + amtsf<=tamt)
        {
            used[i]=true;
            comb1(coins,amtsf+coins[i],tamt,asf + to_string(coins[i])+'-',used);   
            used[i]=false;
        }
    }
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
    vector<bool> used(n);
    int target;
    cin>>target;
    
    comb1(coins,0,target,"",used);
}