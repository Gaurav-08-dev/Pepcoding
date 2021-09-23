  
    int difference(vector<int> &tops,vector<int> &bottoms,int val)
    {
        int count1=0,count2=0;
        
        
        for(int i=0;i<tops.size();i++)
        {
            if(val != tops[i] and val !=bottoms[i])
            {
                return -1;
            }
            if(val!=tops[i])
            {
                count2++;
            }
            if(val != bottoms[i])
            {
                count1++;
            }
        }
        
        return min(count1, count2);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
      int res1=difference(tops,bottoms,tops[0]);
      int res2=difference(tops,bottoms,bottoms[0]);
        
        return min(res1,res2) > 0 ? min(res1,res2) : max(res1,res2);
        
    }