int findPlatform(int arr[], int dep[], int n)
{
	// Your code here 
sort(arr,arr+n);
sort(dep,dep+n);
int ans=0,cMax=1;
int i=1,j=0;

while(i<n and j<n)
{
    if(arr[i]<=dep[j])
    {
        cMax+=1;
        i++;
    }
    else if(arr[i] > dep[j]){
        cMax-=1;
        j++;
    }
    
    ans=max(ans,cMax);
}

return ans;
}