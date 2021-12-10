int countSmallerThanEqualToMid(vector<int> &matrixRow,int mid){
        
        int low=0,high=matrixRow.size()-1;
        while(low<=high)
        {
            int mid1=(low+high)/2;
            
            if(matrixRow[mid1]<=mid){
                low=mid1+1;
            }
            else
            {
                high=mid1-1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here     
        int maxElement=INT_MIN;
        int minElement=INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]< minElement){
                minElement=matrix[i][0];
            }
            
            if(matrix[i][matrix[0].size()-1]> maxElement){
                maxElement=matrix[i][matrix[0].size()-1];
            }
        }
        int low=minElement,high=maxElement,n=matrix.size(),m=matrix[0].size();
        
        while(low<=high)
        {
            int mid= (low+high)/2;
            int count=0;
            
            for(int i=0;i<n;i++){
                count+=countSmallerThanEqualToMid(matrix[i],mid);
            }
            if(count<= (n*m)/2){low=mid+1;}
            else{
                high=mid-1;
            }
        }
        return low;
    }