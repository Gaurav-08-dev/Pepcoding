#include<bits/stdc++.h>
using namespace std;


void print(vector<int> &arr)
{
	for(auto i: arr)
	{
		cout<<i<<"\n";
	}
}


void countSort(vector<int> &arr, int min1, int max1) 
{
    int n=max1-min1+1;

    vector<int> fmap(n,0);
    for(int i=0;i<arr.size();i++)
    {   
        
        fmap[arr[i]-min1]++;
    }
    
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<fmap[i];j++)
        {
            arr[index]=i+min1;
            index++;
        }
    }
    print(arr);
}



void solve()
{
	int n;
    cin>>n;
    vector<int> arr;
    int max1 =INT_MIN;
    int min1 = INT_MAX;
        for (int i = 0; i < n; i++) 
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
          max1 = max(max1, arr[i]);
          min1 = min(min1, arr[i]);
        }
    countSort(arr,min1,max1);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}