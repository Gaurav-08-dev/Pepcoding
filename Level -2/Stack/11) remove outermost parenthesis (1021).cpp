string removeOuterParentheses(string S) {
	string res = "";

	for(auto p1=0,p2=0,o=0,c=0;p2<S.size();++p2){

		if(S[p2]=='(') ++o;
		else ++c;

		if(o==c){

			res+=S.substr(p1+1,p2-p1-1);
			p1=p2+1;
		}
	}

	return res;
}

/**** STACK METHOD ****/
string removeOuterParentheses(string s) {
        string res("");
        stack<char> stack;
        int pos=0, ind=0;
        while(ind!=s.length()){
            if(s[ind]=='(') stack.push(')');
            else stack.pop();
            if(stack.empty()){
                res+=s.substr(pos+1, ind-pos-1);
                pos=ind+1;
            }
            ind++;
        }
        return res;
    }