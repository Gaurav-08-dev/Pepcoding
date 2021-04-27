#include<bits/stdc++.h>
using namespace std;



// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> &arr, int idx, string set, int sos, int tar)
{
	if(idx==arr.size())
	{
		if(sos==tar)
		{
			cout<<set+"."<<"\n";
		}
		return;
	}
    if(sos<=tar)
    {
    	printTargetSumSubsets(arr,idx+1,set+to_string(arr[idx])+",",sos+arr[idx],tar);
    }
    printTargetSumSubsets(arr,idx+1,set,sos,tar);
}



int main() 
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;
    
    vector<int> a;
    
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    
    int tar;
    cin>>tar;

    printTargetSumSubsets(a,0,"",0,tar);
}
