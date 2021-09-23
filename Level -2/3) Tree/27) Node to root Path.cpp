vector<TreeNode*> nodeToRootPath(TreeNode* root, int data)
{
    
    if(!root) {
        vector<TreeNode*> ans; return ans;}
    
    
    vector<TreeNode*> ans;
    if(root->val==data)
    {
        ans.push_back(root);
        return ans;
    }
    vector<TreeNode*> lans=nodeToRootPath(root->left,data);
    if(lans.size()>0)
    {
        lans.push_back(root);
        return lans;
    }
    
    vector<TreeNode*> rans=nodeToRootPath(root->right,data);
    if(rans.size()>0)
    {
        rans.push_back(root);
        return rans;
    }
    
    return ans;
}
