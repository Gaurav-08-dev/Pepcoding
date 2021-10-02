#include<bits/stdc++.h>
using namespace std;

vector<string> gss(string s){
    // write your code here

    if(s.size()==0)
    {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    char ch=s.at(0);
    string res_string=s.substr(1);
    vector<string> rres=gss(res_string);
    vector<string> ans;

    cout<<"_________________"<<"\n\n\n";
    cout<<"rres: ";
    for(auto s:rres)
    {
        cout<<s;
    }
    cout<<"\n\n";

    for(auto s: rres)
    {
        cout<<"s --> "<<s<<"\n"<<"\n";
        ans.push_back(s);
    }

    for(auto s:rres)
    {
        cout<<"ch+s  -->  "<<(ch+s)<<"\n"<<"\n";
        ans.push_back(ch+s);
    }

    cout<<"ans --> ";
    for(auto i: ans)
    {
        cout<<i<<" ";
    }

    cout<<"\n"<<"\n"<<"\n";

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}