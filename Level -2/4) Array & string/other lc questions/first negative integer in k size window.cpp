vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
                                                 
                                                 
  vector<long long> ans;
  long long int j=0; // negative index
  long long int res=0;
  for(long long int i=K-1;i<N;i++)
  {
      while(i>j and (j <= i-K or A[j]>0)){
          j++;
      }
      
      
      if(A[j] < 0)
      {
         res=A[j];
      }
      else
      {
         res=0;
      }
      ans.push_back(res);
  }
  return ans;
                                                 
 }