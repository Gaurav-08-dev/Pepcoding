/* Iterative */

vector<int> BottomView(TreeNode *root)
{
    vector<int> ans;
        if(!root) return ans;
        
        map<int,int> m;
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            
            TreeNode* node=p.first;
            int line=p.second;
            m[line]=node->val;
            if(node->left) q.push({node->left,line-1});
            
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto x: m)
        {
            ans.push_back(x.second);
        }
        
        return ans;
}


/* Recursive */

void solve(TreeNode* root,map<int,pair<int,int>> &m,int level,int distance)
{
    if(!root) return ;
    if(level >= m[distance].second)
        m[distance]={root->val,level};
    solve(root->left,m,level+1,distance-1);
    solve(root->right,m,level+1,distance+1);
}
vector<int> BottomView(TreeNode *root)
{
    vector<int> ans;
        if(!root) return ans;
        
        map<int,pair<int,int>> m;
        solve(root,m,0,0);
        for(auto x: m)
        {
            ans.push_back(x.second.first);
        }
        
        return ans;
}
