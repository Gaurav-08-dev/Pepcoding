class Solution {
public:
    int scoreOfParentheses(string s) {
        
      
    int i=0;
    stack<int> st;
    while(i!=s.size()){
        
        if(s[i]=='('){st.push(-1);}
        else{
            
            if(st.top()==-1){
                st.pop();
                st.push(1);
            }
            else{
                int sum=0;
                while(st.top()!=-1 ){
                    sum+=st.top();st.pop();
                }
                st.pop();
                st.push(2*sum);
            }
        }
        i++;
    }
    int sum=0;
    while(!st.empty()){
        sum+=st.top();st.pop();
    }
    return sum;
    }
};