public static void sort012(int[] arr){
    //write your code here
    
    //i<=k because both are unsolved
    int i=0,j=0,k=arr.length-1;
    while(i<=k)
    {
        if(arr[i]==0)
        {
            swap(arr,i,j);
            i++;j++;
        }
        else if(arr[i]==1)
        {
            i++;
        }
        else
        {
            swap(arr,i,k);
            k--;
        }
    }
  }

  // used for swapping ith and jth elements of array
  public static void swap(int[] arr, int i, int j) {
    System.out.println("Swapping index " + i + " and index " + j);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }