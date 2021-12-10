int solve(vector<int> &arr, int n){
 sort(arr.begin(),arr.end());
 
 int ans=0;
 for(int i=0;i<n;i++){
     ans+=(arr[i]*i);
 }
 return ans;
}
