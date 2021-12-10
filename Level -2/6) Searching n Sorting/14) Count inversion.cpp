/****************** NAIVE APPROACH *************/
int count=0;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }



/******** Using MERGE SORT ****************/


vector<int> mergeSorted(vector<int> &larr,vector<int> &rarr, int &count){
    
    int n1=larr.size();
    int n2=rarr.size();
    
    vector<int> res(n1+n2,0);
    
    int i=0,j=0,k=0;
    
    while(i<n1 and j<n2){
        if(larr[i] > rarr[j]){
            res[k]=rarr[j];
            j++;
            count+=n1-i;
        }
        else{
            res[k]=larr[i];
            i++;
        }
        k++;
    }
    
    while(i < n1){
        res[k]=larr[i];i++;k++;
    }
    while(j < n2){
        res[k]=rarr[j];j++;k++;
    }
    return res;
}
vector<int> mergeSort(vector<int> &arr,int low,int high,int &count){
    if(low==high){
        return {arr[low]};
    }
    
    int mid= low + (high - low)/2;
    
    vector<int> larr=mergeSort(arr,low,mid,count);
    vector<int> rarr=mergeSort(arr,mid+1,high,count);
    
    vector<int> mergedArray= mergeSorted(larr, rarr,count);
    return mergedArray;
}

int countInversion(vector<int> &arr){
    int count=0;
    vector<int> sorted=mergeSort(arr,0,arr.size()-1,count);
    return count;
}