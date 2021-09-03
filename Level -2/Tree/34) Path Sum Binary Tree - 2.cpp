void path(TreeNode* root, int targetSum, int sumSoFar,vector<int> &subres,vector<vector<int>> &ans)
    {
        if(!root) return;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(sumSoFar + root->val == targetSum)
            {
                vector<int> duplicate;
                for(int i:subres)
                {
                    duplicate.push_back(i);
                }
                    duplicate.push_back(root->val);
                ans.push_back(duplicate);
            }
            return;
        }
        subres.push_back(root->val);
        path(root->left,targetSum,sumSoFar+root->val,subres,ans);
        path(root->right,targetSum,sumSoFar+root->val,subres,ans);
        subres.pop_back();
        
    }
vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
          vector<vector<int>> ans;
        if(!root) return ans;
        
        vector<int> subres;
        
        path(root,targetSum,0,subres,ans);
        return ans;
}
