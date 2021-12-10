// USING TWO STACK

  public static void levelOrderLinewiseZZ(Node node){
    // write your code here
    Stack<Node> q=new Stack<>();
    Stack<Node> s=new Stack<>();
     int level=1;
    q.push(node);
    while(q.size()>0)
    {
        while(q.size() >0)
        {
            Node rem=q.pop();
            System.out.print(rem.data + " ");   
            if(level%2==1)
            {
                for(int i=0;i<rem.children.size();i++)
                {
                    s.push(rem.children.get(i));
                }
            }
            else
            {
                for(int i=rem.children.size()-1;i>=0;i--)
                {
                    s.push(rem.children.get(i));
                }
            }
        }
        
        level++;
        System.out.println();
        Stack<Node> temp=q;
        q=s;
        s=temp;
}


// using 1 queue
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root)return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> nodes;
        
        nodes.push(root);
        
        bool flag=false;
        
        while(!nodes.empty()){
            
            int n=nodes.size();
            
            vector<int> levels;
        for(;n>0;n--){
            TreeNode* x=nodes.front(); nodes.pop();
            
            if(x->left) nodes.push(x->left);
            if(x->right) nodes.push(x->right);
            
            levels.push_back(x->val);            
        }    
            
            if(flag) reverse(levels.begin(),levels.end());
            
            ans.push_back(levels);
            flag=!flag;
            
        }
        
        return ans;
    }