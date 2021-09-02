vector<int> verticalOrderSum(TreeNode *root)
{
    vector<int> ans;
    if(!root) return ans;
    map<int,int> m;
    queue<pair<TreeNode*,pair<int,int>>> q;
    
    q.push({root,{0,0}});
    
    while(!q.empty())
    {
        pair<TreeNode*,pair<int,int>> p;
        p=q.front(); q.pop();
        
        TreeNode* node=p.first;
        int count=p.second.first;
        int level=p.second.second;
        
        m[count]+=node->val;
        
        if(node->left) q.push({node->left,{count-1,level+1}});
        if(node->right) q.push({node->right,{count+1,level+1}});
    }
    
    for(auto y: m)
    {
        ans.push_back(y.second);
    }
    
    return ans;
}