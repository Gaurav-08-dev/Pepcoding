#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr,int mid,int d){

	int days=1;
	int cap=0;

	for(int i:arr){
		cap+=i;
		if(cap>mid){
			cap=i;
			days++;
		}
	if(days>d){return false;}
	}
	
	return true;
}

int solve(vector<int> &arr,int d){

	int mx=INT_MIN;
	int sum=0;

	for(int i:arr){
		mx=max(mx,i);
		sum+=i;
	}

	int low=mx,high=sum;
	int ans=0;
	while(low<=high){
		int mid=low + (high-low)/2;

		if(isValid(arr,mid,d)){
			ans=mid;
			high=mid-1;
		}
			else{
				low=mid+1;
			}
	}
	return ans;

}
int main(){
    
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int d;
    cin>>d;
    
    cout<<solve(arr,d);
}