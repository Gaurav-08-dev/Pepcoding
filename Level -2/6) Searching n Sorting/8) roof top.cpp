#include<bits/stdc++.h>
using namespace std;



int solve(vector<int> &arr, int n){
    
    int currentCount=0;
    int ans=INT_MIN;
    
    int i=0,j=1;
    while(j<=n-1)
    {
        if(arr[i]<arr[j])
        {
            currentCount++;
        }
        else {
            // cout<<ans<<" ";
                ans=max(ans,currentCount);    

            currentCount=0;
        }
        i++;j++;
    }
    
   
     ans=max(ans,currentCount);   
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<solve(arr,n);
}