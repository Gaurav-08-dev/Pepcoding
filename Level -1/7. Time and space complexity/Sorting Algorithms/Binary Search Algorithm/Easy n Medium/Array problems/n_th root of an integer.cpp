double multiply(double number, int n){
	double ans=1.0;
	for(i=1;i<=n;i++)
	{
		ans=ans*number;
	}
	return ans;
}

double getNthRoot(int n,int m){

	double low=1,high=m,eps=1e-6;

	while((high  -low) > eps )
	{
		double mid= (low + high) / 2.0;

		if(multiply(mid,n)<m)
		{
			low=mid;
		}
		else{
			high=mid;
		}
	}

	cout<<low<<" "<<high<<endl;

}

int main(){
	int n,m;
	cin>>n>>m;

	getNthRoot(n,m);
}