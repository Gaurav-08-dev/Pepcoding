#include<bits/stdc++.h>
using namespace std;


string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here

    if(ques.size()==0)
    {
    	cout<<asf<<"\n";
    	return;
    }

	int code_index=ques.at(0)-'0';
    string rcode=ques.substr(1);
    string ans=codes[code_index];
    // cout<<ans<<"\n";
    for(int i=0;i<ans.size();i++)
    {
    	char ch=ans.at(i);
    	printKPC(rcode,asf + ch);
    }
}



int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string str;
    cin >> str;
    printKPC(str, "");

}