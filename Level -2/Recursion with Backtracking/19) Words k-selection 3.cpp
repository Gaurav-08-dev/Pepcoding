#include<bits/stdc++.h>
using namespace std;

// cc -> current character
void word(string ustr,int cc,map<char,int> &m,string asf,int k)
{   
    int ssf=asf.size();
    if(ssf == k)
    {
        cout<<asf<<"\n";
        return;
    }
    
    if(cc == ustr.size()) return;
    char ch=ustr.at(cc);
    int freq=m[ch];
    
    // yes call
    for(int i=freq;i>0;i--)
    {
        if(i+ssf <= k)
        {
            string str="";
            for(int j=0;j<i;j++)
            {
                str+=ch;
            }
            
            word(ustr,cc+1,m,asf + str,k);
        }
    }
    // no call
    word(ustr,cc+1,m,asf,k);
}

int main()
{
    string str;
    cin>>str;
    int n;
    cin>>n;
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
    
    map<char,int> f;
    for(int i=0;i<str.size();i++)
    {
        if(f.find(str[i])==f.end())
        {
            f[str[i]]=1;
        }
        else
        {
            f[str[i]]++;
        }
    }
    
    word(ustr,0,f,"",n);
    
}