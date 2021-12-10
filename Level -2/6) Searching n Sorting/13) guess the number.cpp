 public static int guessNumber(int n) {
    //write your code here
    int low=1, high=n;
        
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(guess(mid)==0){
                return mid;
            }
            else if(guess(mid)<0){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
  }