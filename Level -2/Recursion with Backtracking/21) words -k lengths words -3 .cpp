#include<bits/stdc++.h>
using namespace std;

void word(string ustr)
{
	
}

int main()
{
    string str;
    cin>>str;
    
    int k;
    cin>>k;

    list<char> m;
    string ustr;
    for(auto i:str)
    {
    	if(find(m.begin(),m.end(),str[i])==m.end())
    		ustr+=i;
    }
       
    word();
}




