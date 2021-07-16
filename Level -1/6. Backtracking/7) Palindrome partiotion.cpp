class Solution {
public:
    
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
    
    void solve(string s,int index,vector<vector<string>> &ans,vector<string> &pString)
    {
        
        if(index==s.size())
        {
            ans.push_back(pString);
            return;
        }

        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
               {
                   pString.push_back(s.substr(index,i - index + 1));
                   solve(s,i+1,ans,pString);
                   pString.pop_back();
               }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        
        vector<vector<string>> ans;
        vector<string> pString;
        
        solve(s,0,ans,pString);
        
        return ans;
    }
};