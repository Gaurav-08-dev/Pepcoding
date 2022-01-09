/***** TC-> O(N) SC-> O(N) *****/
class Solution {
public:
    int minInsertions(string s) {
        
        stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='('){
               st.push(s[i]);
           }
            else{
                
                if(i+1<s.size() and s[i+1]==')'){
                    i++;
                }
                else{
                    count++;
                }
                
                if(st.empty()) count++;
                    else{
                        st.pop();
                    }
            }
        }
        
        while(!st.empty()){
            st.pop();
            count+=2;
        }
        
        return count;
    }
};


/***** TC-> O(N) SC-> O(1) *****/
class Solution {
public:
    int minInsertions(string s) {
        
        int st=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='('){
               st++;
           }
            else{
                
                if(i+1<s.size() and s[i+1]==')'){
                    i++;
                }
                else{
                    count++;
                }
                
                if(st==0) count++;
                    else{
                        st--;
                    }
            }
        }
        
        while(st){
            st--;
            count+=2;
        }
        
        return count;
    }
};