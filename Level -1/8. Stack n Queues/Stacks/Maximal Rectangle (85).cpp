 
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
         if(matrix.size()==0 || matrix[0].size()==0)
        {
            return 0;
        }
        int n=matrix.size(),m=matrix[0].size();
        vector<int> arr(m,0);
        int res=0;

        for(int i=0;i<n;i++)
        {
            // prepare array for largest area histogram
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    arr[j]=0;
                }
                else
                {
                    arr[j]+=matrix[i][j] - '0';
                }
            }
            res=max(res,lah(arr));
        }
        return res;
    }



    // lah= largest area histogram