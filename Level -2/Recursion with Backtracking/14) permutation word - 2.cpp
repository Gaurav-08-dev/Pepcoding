#include<bits/stdc++.h>
using namespace std;

void perm(int cc,string str,vector<char> &spots,map<char, int> &m)
{
    if(cc == str.size())
    {
        for(auto i:spots)
        {
            cout<<i;
        }
        cout<<"\n";
        return;
    }
    char ch=str.at(cc);
    int last_index=m[ch]; //last spot
    
    for(int i=last_index+1;i<spots.size();i++)
    {
        if(spots[i]=='A') // to check if its null
        {
            spots[i]=ch;
            m[ch]=i;
            perm(cc+1, str,spots,m);
            spots[i]='A';
            m[ch]=last_index; 
        }
    }
}
void solve()
{
    string str;
    cin>>str;
    vector<char> spots(str.size(),'A');
    map<char,int> m;
    for(int i=0;i<str.size();i++)
    {
        if(m.find(str[i])==m.end())
        {
            m[str[i]]=-1;
        }
    }
    perm(0,str,spots,m);
}

int main()
{

    solve();
}