// Median = (1+n)/2 th element


/* 

* 	for a no. to be median there should be exactly n/2 numbers which 
	are less than this number

* 	Median for an Odd numbered matrix = 1+ (rows)* columns/2 th smallest number

*   x is the median only if x is an element of the matrix and 
    number of matrix elements <= x equals (1 + (row*column))/2;
    

*   so to find out median we need to search all the element which are either 
	smaller or equal till 1+r*c/2 th element

*/

/* ALGORITHM*/

/*  Find  min and max elements of matrix because median will always lie in min and max element

	-> min  = compare first element of each row
	-> max  = compare last element of each row

	Find mid of min and max

	get count of no. in the matrix less than mid. And accordingly change min and max

    if the no. of elements in matrix <= x is 1+ N*M / 2 and x is in matrix then x is a median


*/


/* time complexity  --> O(N*log(M))
    
    space complexity  --> O(1) */



int min=INT_MAX;
    int max=INT_MIN;
    
    int desired_count=(1+(r*c))/2;
    
    for(int i=0;i<r;i++)
    {
        if(matrix[i][0]<min)
        {
            min=matrix[i][0];
        }
        if(matrix[i][c-1]>max)
        {
            max=matrix[i][c-1];
        }
    }
    
    int counter=0;
    
    while(min<max)
    {
        counter=0;
        
        int mid=min + (max-min)/2;
        
        for(int i=0;i<r;i++)
        {
            counter+=upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
        }
        
        if(counter<desired_count)
        {
            min=mid+1;
            
        }
        else
        {

        	/* if we have found the median but we have to check :
        	if any other element exists for which the no. of element is <= desired_count
        	This is why when count==element we do max=mid ,instead of return at that point*/
        	
            max=mid;
        }
        
    }
    
    return min;

