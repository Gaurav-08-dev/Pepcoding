#include<bits/stdc++.h>
using namespace std;

string codes[]={":;","abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz" };

vector<string> get_str(string s)
{

	if(s.size()==0)
	{
		vector<string> bres;
		bres.push_back("");
		return bres;
	}

	int index=s.at(0)-'0';
	string code=codes[index];
	string ros=s.substr(1);

	vector<string> rres=get_str(ros);
	vector<string> mres;

	for(int i=0;i<code.size();i++)
	{
		// cout<<code<<"\n";
		char ch=code.at(i);
		for(auto s: rres)
		{
			// cout<<"ch+s= "<< ch+s<<"\n";
			mres.push_back(ch+s);
		}
	}

	for(auto i: mres)
	{
		cout<<i<<" ";
	}
	cout<<"\n";

	return mres;

}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    string s;
    cin >> s;
    vector<string> ans = get_str(s);
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