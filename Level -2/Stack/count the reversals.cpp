int countRev (string s)
{
    stack<char> st;
        
        for(int i=0;i<s.size();i++){
            
            if((s[i])=='{' or st.size()==0) st.push(s[i]);
            else{
                
                if((st.top())=='{'){st.pop();}
                
                else{
                    st.push(s[i]);
                }
            }
        }
        
        if(st.size() %2!=0) return -1;
        
        int op=0,cl=0;
        while(st.size() > 0){
            char ch=st.top(); st.pop();
            
            if(ch=='{'){op++;}
            else{cl++;}
        }
        
        return (int) ceil(op/2.0) + ceil(cl/2.0);
}