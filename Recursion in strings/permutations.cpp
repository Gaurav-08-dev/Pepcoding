#include <bits/stdc++.h>
using namespace std;


vector<string> perm(string str)
{

	if(str.size()==0)
	{
		vector<string> bres;
		bres.push_back("");
		return bres;
	}

	vector<string> ans;

	for(int i=0;i<str.size();i++)
	{
		char ch=str.at(i);
		string rstr=str.substr(0,i) + str.substr(i+1);

		vector<string> rres=perm(rstr);
		for(auto i : rres)
		{
			ans.push_back(ch+i);
		}
	}
	return ans;
}





void printPermutations(string str, string asf)
{
	if(str.size()==0)
	{
		cout<<asf<<"\n";
		return;
	}

	for(int i=0;i<str.size();i++)
	{
		char ch=str.at(i);
		string rres=str.substr(0,i)+ str.substr(i+1);
		printPermutations(rres,asf+ch);
	}

}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string str;
    cin>>str;
    // printPermutations(str,"");

    vector<string> ans=perm(str);

    for(auto i: ans)
    {
    	cout<<i<<"\n";
    }
}