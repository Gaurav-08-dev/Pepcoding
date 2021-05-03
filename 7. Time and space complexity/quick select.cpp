#include<bits/stdc++.h>
using namespace std;


void swap(vector<int>&arr, int i, int j)
{
cout<<"Swapping " << arr[i] << " and " << arr[j]<<"\n";
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}

int partition_index(vector<int> &arr,int pivot,int low,int high)
{
cout<<"pivot -> "<<pivot<<"\n";
int i=low,j=low;

while(i<=high)
{
  if(arr[i]<=pivot)
  {
    swap(arr,i,j);
    i++;
    j++;
  }
  else
  {
    i++;
  }
}
cout<<"pivot index -> "<<j-1<<"\n";
return j-1;
}


int quickSelect( vector<int>&arr, int lo, int hi, int k,int n) {
//write your code here
  
  
  int pivot=arr[hi];
  int pi=partition_index(arr,pivot,lo,hi);
  int ans=0;
  if(pi==n-k) 
  {
    ans=pivot;
  }
  else if(pi>n-k)
  {
    ans=quickSelect(arr,lo,pi-1,k,n); 
  }
  else
  {
    ans=quickSelect(arr,pi+1,hi,k,n);
  }
  return ans;
}







// void print(vector<int>&arr) 
// {
//   for (int i = 0; i < arr.size(); i++) {
//     cout<<arr[i] <<" ";
//   }
//   cout<<"\n";
// }

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

int k;
cin>>k;

cout<<quickSelect(arr,0,arr.size()-1,k-1,n)<<"\n";
}


int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  solve();

}
