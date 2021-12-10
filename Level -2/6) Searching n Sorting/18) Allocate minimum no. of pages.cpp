
bool isValid(vector<int> &arr,int mid, int m){

	int students=1;
	int pages=0;
	for(int i: arr){
		pages+=i;
		if(pages > mid){
			pages=i;
			students++;
		}
	}

	if(students > m){
		return false;
	}
	else{
		return true;
	}

}

int solve(vector<int> &arr,int m){


if(arr.size() < m) return -1;
	int mx=INT_MIN,sum=0;

	for(int i:arr){
		mx=max(i,mx);
		sum+=i;
	}


	int low=mx,high=sum;
	int ans=0;
	while(low<=high){
		
		int mid=low + (high-low)/2; // burden of pages

		if(isValid(arr,mid,m)){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}

	return ans;
}