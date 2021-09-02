#include<bits/stdc++.h>
using namespace std;

void comb1(vector<int> coins,int amtsf,int tamt,string asf)
{
    if(amtsf == tamt)
    {
        cout<<asf+'.'<<"\n";
        return;
    }
    for(int i=0;i<coins.size();i++)
    {
        if(coins[i] + amtsf<=tamt)
        {
            comb1(coins,amtsf+coins[i],tamt,asf + to_string(coins[i])+'-');  
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
    int target;
    cin>>target;
    
    comb1(coins,0,target,"");
}