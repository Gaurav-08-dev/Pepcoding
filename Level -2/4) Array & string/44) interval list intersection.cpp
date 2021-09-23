 vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        
        vector<vector<int>> res;
        
        int n1=firstList.size();
        int n2=secondList.size();
        
        if(n1==0 or n2==0)
        {
            return res;
            
        }
        
        int p1=0,p2=0;
        
        while(p1<n1 and p2<n2)
        {
            int s1=firstList[p1][0],s2=secondList[p2][0];
            int e1=firstList[p1][1],e2=secondList[p2][1];
            
            if(s2 > e1)
            {
                p1++;
            }
            else if (s1 > e2)
            {
                p2++;
            }
            else
            {
                res.push_back({max(s1,s2),min(e1,e2)});
                if(e1 > e2)
                {
                    p2++;
                }
                else
                {
                    p1++;
                }
            }
            
        }
        
        return res;
    }