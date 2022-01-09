   bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;  int index=0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(!st.empty() and st.top()==popped[index])
            {
                st.pop();
                index++;
            }
        }
        
        return index==popped.size();
    }