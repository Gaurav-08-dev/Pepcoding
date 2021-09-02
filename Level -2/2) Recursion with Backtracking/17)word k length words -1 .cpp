#include<bits/stdc++.h>
using namespace std;
    
void word(string ustr,int ssf,vector<char> &slots,int i)
{
    if(i==ustr.size())
    {
        if(ssf == slots.size())
        {
            for(auto c: slots)
            {
                cout<<c;
            }
            cout<<"\n";
        }
        return;
    }
    char c=ustr.at(i);
    
    // yes call
    for(int s=0;s<slots.size();s++)
    {
        if(slots[s]=='A')
        {
            // place
            slots[s]=c;
            word(ustr,ssf+1,slots,i+1);
            // place
            slots[s]='A';
        }
    }
    word(ustr,ssf,slots,i+1);
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
    // cout<<ustr;
    vector<char> slots(k,'A');
    word(ustr,0,slots,0);
    
}