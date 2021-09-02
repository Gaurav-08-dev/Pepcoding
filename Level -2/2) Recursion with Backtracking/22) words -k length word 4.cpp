#include<bits/stdc++.h>
using namespace std;

// cs -> current slot , ts -> total slot
void word(string ustr, int cs, int ts, string asf, map<char, int > &fmap)
{
    if(cs == ts)
    {
        cout<<asf<<"\n";
        return ;
    } 
    for(int i=0;i<ustr.size();i++)
    {
        char ch=ustr[i];
        int freq=fmap[ch];
        if(freq > 0)
        {
            fmap[ch]-=1;
            word(ustr,cs+1,ts,asf + ch,fmap);
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
    
    map<char,int> fmap;
    for(int i=0;i<str.size();i++)
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
    
    word(ustr,0,k,"",fmap);
}