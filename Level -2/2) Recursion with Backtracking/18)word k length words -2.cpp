#include<bits/stdc++.h>
using namespace std;

// cs -> current slot , ts -> total slot
void word(string ustr,set<char> &visited,int cs,int ts,string asf)
{
    if(cs == ts)
    {
        cout<<asf<<"\n";
        return;
    }
    
    for(int i=0;i<ustr.size();i++)
    {
        char ch=ustr.at(i);
        
        if(visited.find(ch)==visited.end())
        {
            // place
            visited.insert(ch);
            
            word(ustr,visited,cs+1,ts,asf + ch);
            
            // unplace
            visited.erase(ch);
        }
    }
}

int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    string ustr;
    list<char> m;
    for(int i=0; str[i];i++)
    {
        auto it=find(m.begin(),m.end(),str[i]);
        if(it==m.end())
            m.push_back(str[i]);
    }
    
    for(auto i:m)
    {
        ustr+=i;
    }
    // cout<<ustr;
    set<char> visited;
    word(ustr,visited,0,k,"");
    
    
}