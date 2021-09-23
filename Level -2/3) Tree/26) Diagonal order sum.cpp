/* Iterative */
vector<int> diagonalOrderSum(TreeNode *root)
{
    vector<int> ans;
    if(!root) return ans;
    
    
    queue<TreeNode*> q;
    q.push(root);
    int sum=0;
    while(!q.empty())
    {
        int factor_size=q.size();
        while(factor_size--)
        {
            TreeNode* factor=q.front();
            q.pop();
            
            while(factor)
            {
              sum+=factor->val;
              if(factor->left) q.push(factor->left);
              
              factor=factor->right;
            }
        }
        
        ans.push_back(sum);
        sum=0;
    }
    
    return ans;
}


/* Recursive */

void solve(TreeNode *root,map<int,int> &m,int count)
{
    if(!root) return;
    
    m[count]+=root->val;
    solve(root->left,m,count+1);
    solve(root->right,m,count);
}

vector<int> diagonalOrderSum(TreeNode *root)
{
    vector<int> ans;
    map<int,int> m;
    if(!root) return ans;
    solve(root,m,0);
    for(auto y: m)
    {
        ans.push_back(y.second);
    }
    return ans;
}