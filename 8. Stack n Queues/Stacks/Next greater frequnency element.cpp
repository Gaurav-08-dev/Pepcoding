#include<bits/stdc++.h>
using namespace std;


void next_freq(vector<int> &arr,int n)
{
	int n1=*max_element(arr.begin(),arr.end());

	vector<int> ans(n,-1);
	// prepare a frequency map
	vector<int> freq(n1,0);
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
	}

	// push the position of first element to stack 

	stack<int > s;
	s.push(0);

	for(int i=1;i<n;i++)
	{
		if(freq[s.top()]>freq[arr[i]])
		{
			s.push(i);
		}
		else
		{
			while(s.size()!=0 and freq[arr[s.top()]]<freq[arr[i]])
			{
				ans[s.top()]=arr[i];
				s.pop();
			}
			s.push(i);
		}
	}

	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}


}

void solve()
{

	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}

next_freq(arr,n);	
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}