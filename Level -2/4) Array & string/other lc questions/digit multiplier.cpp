string getSmallest(long long num) {
        // code here
        string res="";
        if(num==1) return "1";
        
        for(int i=9;i>=2;i--)
        {
            while(num%i==0)
            {
                res=to_string(i)+res;
                num/=i;
            }
        }
        
        return res.size()==0 or num!=1 ? "-1" : res;
    }