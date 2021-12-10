 vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> res;
        int i=0,j=0;
        
        while(i< n and j<m){
            
            while(i+1 < n and arr1[i]==arr1[i+1]){
                i++;
            }
            while(j+1 < m and arr2[j]==arr2[j+1]){
                j++;
            }
            
            if(arr1[i]<arr2[j]){
                res.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i]>arr2[j]){
                res.push_back(arr2[j]);
                j++;
            }
            else{
                res.push_back(arr1[i]);
                i++;j++;
            }
            
        }
        
        while(i<n){
            if(i+1==n or arr1[i]!=arr1[i+1])
                res.push_back(arr1[i]);
            i++;
        }
        while(j<m){
            if(j+1==n or arr2[j]!=arr2[j+1])
                res.push_back(arr2[j]);
            j++;
        }
        
        return res;
    }