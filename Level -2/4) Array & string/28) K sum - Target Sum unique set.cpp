 private static List<List<Integer>> twoSum(int[] arr, int st, int end, int target) {
        int left = st;
        int right = end;
        List<List<Integer>> res = new ArrayList<>();
        while(left < right) {
            if(left != st && arr[left] == arr[left - 1]) {
                left++;
                continue;
            }
            int sum = arr[left] + arr[right];
            if(sum == target) {
                List<Integer> subres = new ArrayList<>();
                subres.add(arr[left]);
                subres.add(arr[right]);
                res.add(subres);
                left++;
                right--;
            } else if(sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
    
  public static List<List<Integer>> helper(int[] arr, int target, int si, int k)
  {
    
    if(k==2)
    {
        return twoSum(arr,si,arr.length-1,target);
    }
    int n=arr.length;  
    List<List<Integer>> res=new ArrayList<>();
    
    for(int i=si;i<n-(k-1);i++)
    {
        if(i!=si && arr[i]==arr[i-1]) continue;
        int val1=arr[i];
        int targ=target-val1;
        
        List<List<Integer>> subres=helper(arr, targ,i+1,k-1);
        
        for(List<Integer> list: subres)
        {
            list.add(val1);
            res.add(list);
        }
    }