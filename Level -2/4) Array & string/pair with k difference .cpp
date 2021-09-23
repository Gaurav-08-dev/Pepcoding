
bool findPair(int arr[], int size, int n){
    //code
    
    
    sort(arr,arr+ size);
    int i=0,j=i+1;
    
    while(j< size)
    {
        if(arr[j] - arr[i]==n)
        {
            return true;
        }
        else if(arr[j] - arr[i] > n)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    
    return false;
    
}