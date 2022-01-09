int minAddToMakeValid(string s) {
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            
            if((s[i])=='[' or st.size()==0) st.push(s[i]);
            else{
                
                if((st.top())==']'){st.pop();}
                
                else{
                    st.push(s[i]);
                }
            }
        }
        int pair= st.size();
        return (int) ceil(pair/2.0);
    }