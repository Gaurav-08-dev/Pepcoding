
int countHours(vector<int>& arr, int mid){

	int count=0;

	if(mid==0) return INT_MAX;

	for(int i: arr){
		if(i%mid!=0) count++;

		count+=i/mid;
	}
	return count;
}

int solve(vector<int> &arr,int h)
{
	int sum=0;
	int mx=INT_MIN;

	for(int i: arr){
		sum+=i;
		mx=max(mx,i);
	}

	int low=sum/h,high=mx;
	while(low<high){

		int mid=low + (high-low)/2;

		int hours=countHours(arr,mid);
		if(hours>h){
			low=mid+1;
		}
		else{
			high=mid;
		}
	}

	return high;
}