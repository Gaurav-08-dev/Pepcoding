#include<bits/stdc++.h>
using namespace std;



int getNum(string str,unordered_map<char,int> &fmap)
{
	 int num=0;
	for(int i=0;i<str.size();i++)
	{
		num = (num * 10 + fmap[str[i]]);
	}

	return num;
}

void solution(string uniqueStr,int index, unordered_map<char,int > &fmap,vector<bool> &usedNumbers,string s1,string s2,string s3)
{
	if(index==uniqueStr.size())
	{
		int num1=getNum(s1,fmap);
		int num2=getNum(s2,fmap);
		int num3=getNum(s3,fmap);

		
		if(num1+num2==num3)
		{
			// cout<<num1<<" "<<num2<<" "<<num3<<"\n";
			for(int i=0;i<26;i++)
			{
				char ch=(char)(97 + i);
				// cout<<ch<<"\n";
				if(fmap.find(ch)!=fmap.end())
				{
					cout<<ch<<"-"<<fmap[ch]<<" ";
				}

				// cout<<it.first<<"-"<<it.second<<" ";
			}
			cout<<"\n";
		}
		return;
	}

	char ch=uniqueStr.at(index);
	for(int i=0;i<=9;i++)
	{
		if(usedNumbers[i]==false)
		{
			fmap[ch]=i;
			usedNumbers[i]=true;
			solution(uniqueStr,index+1,fmap,usedNumbers,s1,s2,s3);
			fmap[ch]=-1;
			usedNumbers[i]=false;
		}
	}
}

void solve()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;

	unordered_map<char,int> fmap;
	string uniqueStr="";

	for(int i=0;i<s1.size();i++)
	{
		if(fmap.find(s1[i])==fmap.end())
		{
			fmap[s1[i]]=-1;
			uniqueStr+=s1[i];
		}
	}


	for(int i=0;i<s2.size();i++)
	{
		if(fmap.find(s2[i])==fmap.end())
		{
			fmap[s2[i]]=-1;
			uniqueStr+=s2[i];
		}
	}


	for(int i=0;i<s3.size();i++)
	{
		if(fmap.find(s3[i])==fmap.end())
		{
			fmap[s3[i]]=-1;
			uniqueStr+=s3[i];
		}
	}

	vector<bool> usedNumbers(10,false);
	solution(uniqueStr,0,fmap,usedNumbers,s1,s2,s3);

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}