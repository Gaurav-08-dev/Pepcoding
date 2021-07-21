#include<bits/stdc++.h>
using namespace std;

void word(int cc,string ustr,int ssf,int ts,string asf)
{
    if(cc==ustr.size())
    {
        if(ssf==ts)
        {
            cout<<asf<<"\n";
        }
        return;
    }
    char ch=ustr.at(cc);
    
    // yes call
    word(cc+1,ustr,ssf+1,ts,asf + ch);
        
    // No call
    word(cc+1,ustr,ssf,ts,asf);
}


int main()
{
    string str;
    int k;
    cin>>str;
    cin>>k;
    string ustr;
    map<char,int> m;
    for(int i=0; str[i];i++)
    {
        if(m.find(str[i])==m.end())
            m[str[i]]=1;
        else
            m[str[i]]++;
    }
    
    for(auto i:m)
    {
        ustr+=i.first;
    }
    word(0,ustr,0,k,"");
}