    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> m;
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]=i;
        }
        
        vector<int> ans;
        int prev=0;
        int cmax=0;
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s.at(i);
            cmax=max(cmax,m[ch]);
            if(cmax==i)
            {
                ans.push_back(i-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }