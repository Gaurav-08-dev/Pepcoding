#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr)
{	
	int oldBuy=-arr[0],oldSell=0,oldCool=0;
	
	for(int i=1;i<arr.size();i++)
	{
	    int newBuy=0;
	    int newSell=0;
	    int newCool=0;
	    
	    if(oldCool - arr[i] > oldBuy)
	    {
	        newBuy=oldCool - arr[i];
	    }
	    else
	    {
	        newBuy=oldBuy;
	    }
	    
	   // sold state
	    if(oldBuy + arr[i] > oldSell)
	    {
	        newSell=oldBuy + arr[i];
	    }
	    else
	    {
	        newSell=oldSell;
	    }
	    
	   // coolDown state
	   if(oldCool < oldSell)
	   {
	       newCool=oldSell;
	   }
	   else
	   {
	       newCool=oldCool;
	   }
	   
	   oldBuy=newBuy;
	   oldSell=newSell;
	   oldCool=newCool;
	}
	
	return oldSell;
	
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    
    cout<<maxProfit(arr);
}