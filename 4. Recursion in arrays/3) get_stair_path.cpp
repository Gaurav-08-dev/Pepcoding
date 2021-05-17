// for problems where movements are given :
// identify source and destination and intermediates



#include<bits/stdc++.h>
using namespace std;

vector<string> get_str(int n)
{
	if(n<=0)
	{
		vector<string> bres;
		if(n==0)
		{
		bres.push_back("");
		}
		return bres;
	}

	vector<string> ans;



	for(int jump=1; jump<=3 and n-jump>=0;jump++)
	{
		vector<string> rres=get_str(n-jump);
		// for(auto s: rres)
		// {
		// 	cout<<s;
		// }
		for(auto s: rres)
		{

			ans.push_back(to_string(jump) + s);
		}
	}
	return ans;
}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int s;
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