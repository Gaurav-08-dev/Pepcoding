string reverseParentheses(string s) 
    {
        stack<char>stk;
        string res;
        for(char c:s)
        {
            string temp;
            if(c=='(')
                stk.push(c);
            else if(c==')')
            {
                while(stk.top()!='(')
                    temp+=stk.top(),stk.pop();
                stk.pop();
                if(stk.empty())
                    res+=temp;
                else
                    for(char c:temp)
                        stk.push(c); 
            }
            else if(stk.empty())
                res+=c;
            else
                stk.push(c);
        }
        return res;
    }