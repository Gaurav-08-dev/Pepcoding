#include<bits/stdc++.h>
using namespace std;

// ts -> total spot , cs -> current spot
void word(int cs,int ts,string ustr,map<char,int> &fmap,int li,string asf)
{
    
    if(cs == ts)
    {
        cout<<asf<<"\n";
        return;
    }

    for(int i=li; i<ustr.size();i++)
    {
        char ch =ustr.at(i);
        int freq=fmap[ch];
        if(freq>0)
        {
            fmap[ch]-=1;
            word(cs+1,ts,ustr,fmap,i,asf + ch);
            fmap[ch]+=1;
        }
    }
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    list<char> m;
    for(int i=0;i<str.size();i++)
    {
        if(find(m.begin(),m.end(),str[i])== m.end())
        {
            m.push_back(str[i]);
        }
    }
    
    string ustr;
    for(auto i: m)
    {
        ustr+=i;
    }
    
    map<char, int> fmap;
    
    for(int i=0;str[i];i++)
    {
        if(fmap.find(str[i])==fmap.end())
        {
            fmap[str[i]]=1;
        }
        else
        {
            fmap[str[i]]++;
        }
    }
    
    word(0,k,ustr,fmap,0,"");
    
    
}
