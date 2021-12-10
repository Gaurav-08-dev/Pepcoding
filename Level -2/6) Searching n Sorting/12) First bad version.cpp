
  public static int firstBadVersion(int n) {
    //write your code here
    
    int low=0,high=n;
    int ans=-1;
    
    while(low<=high){
        
        int mid=low + (high-low)/2;
        
        if(isBadVersion(mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
  }