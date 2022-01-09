/***** TC-> O(N) SC-> O(N) *****/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        string res="";
        for(int i=0;i<s.size();i++){
           
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){s[i]='#';}
                else{
                    st.pop();
                }
            }  
        }
        
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
      
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#') 
            {
                res+=s[i];
            }
        }
        
        return res;
    }
};

/****  TC-> O(N) sc->O(1) ****/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int st=0;
        for(int i=0;i<s.size();i++){
           
            if(s[i]=='('){
                st++;
            }
            else if(s[i]==')'){
                if(st==0){s[i]='#';}
                else{
                    st--;
                }
            }  
        }
        
        st=0;
        for(int i=s.size()-1;i>=0;i--){
           
            if(s[i]==')'){
                st++;
            }
            else if(s[i]=='('){
                if(st==0){s[i]='#';}
                else{
                    st--;
                }
            }  
        }
        s.erase(remove(s.begin(),s.end(),'#'),s.end());
        
        return s;
    }
};