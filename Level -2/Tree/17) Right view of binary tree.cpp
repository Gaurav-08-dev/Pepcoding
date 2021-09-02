vector<int> rightView(TreeNode *root)
{
    vector<int> ans;
    if(!root) return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(q.size()>0)
    {
        int n=q.size();
        
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(i==0) ans.push_back(temp->val);
            if(temp->right!=NULL) q.push(temp->right);
            if(temp->left!=NULL) q.push(temp->left);
        }
    }
    
    return ans;
}