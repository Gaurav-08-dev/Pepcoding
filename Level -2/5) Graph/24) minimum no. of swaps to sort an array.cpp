#include<bits/stdc++.h>
using namespace std;

int main()
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
    
    vector<pair<int,int>> pArr;
    
    for(int i=0;i<n;i++)
    {
        pArr.push_back({arr[i],i});
    }
    
    sort(pArr.begin(),pArr.end());
    
    vector<bool> visited(n,false);
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        if(visited[i]==true or pArr[i].second==i)
        {
            continue;
        }
        int cycleLength=0;
        int j=i;
        while(visited[j]==false)
        {
            visited[j]=true;
            cycleLength++;
            j=pArr[j].second;
        }
        ans+=cycleLength-1;
    }
    
    cout<<ans;
    
}