/* Recursive approach */


// i== starting point array , j== end point of array
int matrixChain(vector<int> &arr, int i,int j){

	if(i==j) return 0;

	int k; 
	int min=INT_MAX;
	int count;

	// place parenthesis at different places
    // between first and last matrix, recursively
    // calculate count of multiplications for
    // each parenthesis placement and return the
    // minimum count

    for(int k=i;k<j;k++){

    	count=matrixChain(arr,i,k) + matrixChain(arr,k+1,j) + arr[i-1]*arr[k]*arr[j]; 

    	if(count < min) min=count;

    }

    return min;
}

/**/