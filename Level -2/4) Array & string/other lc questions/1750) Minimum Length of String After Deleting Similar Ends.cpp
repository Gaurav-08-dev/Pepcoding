    int minimumLength(string s) {
        
        int left =0, right=s.size()-1;
        while(right>left)
        {
            if(s[left]!=s[right])
            {
                break;
            } 
            while(left<=right and s[left]==s[right]) left++;
            
            while(left<=right and s[right]==s[left-1]) right--;
        }
        
        return right-left +1;
        
    }