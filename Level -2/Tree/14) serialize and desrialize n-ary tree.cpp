void serialize1(Node* root,string &s)
{
    s.append(to_string(root->val)+"#");
    for(auto child: root->children)
    {
        serialize1(child,s);
    }
    s.append("NULL#");
}

string serialize(Node* root)
{
    if(root == NULL) return "NULL#";
    string s;
    serialize1(root,s);
    return s;
}

// Decodes your encoded data to tree.
Node* deserialize(string s)
{
    if(s=="NULL#") return NULL;
    vector<string> q;
        string s1;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                // cout<<s<<"\n";
                q.push_back(s1);
                s1="";
                continue;
            }
            s1+=s[i];
        }
        
        if(s1.size()!=0) q.push_back(s1);
        
        Node* root=new Node(stoi(q[0]));
        
        stack<Node*> st;
        
        for(int i=1;i<q.size();i++)
        {
            if(q[i]=="NULL"){ st.pop();}
            else
            {
                Node* nn=new Node(stoi(q[i]));
                st.top()->children.push_back(nn);
                st.push(nn);
            }
        }
        
        
        
        return root;
}
