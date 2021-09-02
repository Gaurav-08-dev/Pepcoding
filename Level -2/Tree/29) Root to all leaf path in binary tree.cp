/* return vector<vector<int>> */

void dfs(TreeNode* root,vector<vector<int>> &ans,vector<int> curr)
{
    if(!root) return;
        if(root->left ==NULL and root->right==NULL){
        vector<int> dup;
            for(int x: curr)
            {
                dup.push_back(x);
            }
            
            dup.push_back(root->val);
            ans.push_back(dup);
            return;
        }
        
        curr.push_back(root->val);
        dfs(root->left,ans,curr);
        dfs(root->right,ans,curr);
        curr.pop_back();
    
}
vector<vector<int>> rootToAllLeafPath(TreeNode* root)
{    
    vector<int> curr;
    vector<vector<int>> ans;
    dfs(root,ans,curr);
    return ans;
}

/* */

void dfs(TreeNode*root,vector<string> &ans,string str)
{
    if(!root) return;
    if(root->left or root->right)
        str+=to_string(root->val)+"->";
    else {
        str+=to_string(root->val);
        ans.push_back(str);
    }
    dfs(root->left,ans,str);
    dfs(root->right,ans,str);
}

vector<string> binaryTreePaths(TreeNode* root) {
string str="";
    vector<string> ans;
    dfs(root,ans,str);
    return ans;
}
