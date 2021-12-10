#include<bits/stdc++.h>
using namespace std;

int findSum(vector<int> &arr, int mid){

	int sum=0;

	for(int i:arr){

		if(i%mid!=0){sum+=i/mid +1;}
			else{
				sum+=i/mid;
			}
	}

	return sum;
}


int solve(vector<int> &arr,int threshold){

	int mx=INT_MIN;

	for(int i:arr){
		mx=max(mx,i);
	}

	int low=1,high=mx;
	int ans;
	while(low<=high){

		int mid=low + (high-low)/2; // possible divisor

		int sum=findSum(arr,mid);
		if(sum > threshold){
			low=mid+1;
		}
		else{
			ans=mid;
			high=mid-1;
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
    int h;
    cin>>h;
    
    cout<<solve(arr,h);
}