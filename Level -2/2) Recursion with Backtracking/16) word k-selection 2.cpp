#include<bits/stdc++.h>
using namespace std;

void word(string ustr,int ssf,int ts,string asf,int lc)
{
    if(ssf == ts)
    {
        cout<<asf<<"\n";
        return;
    }
    for(int i=lc+1;i<ustr.size();i++)
    {
        char ch=ustr.at(i);
        // yes call
        word(ustr,ssf+1,ts,asf + ch,i);

    }
}


int main()
{
    string str;
    int k;
    cin>>str;
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
    word(ustr,0,k,"",-1);
}