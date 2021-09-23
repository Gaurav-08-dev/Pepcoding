/* Recursive */

void solve(TreeNode* root,int h,int v,map<int,multiset<pair<int,int>>> &m)
    {
        if(!root) return;
        
        m[h].insert({v,root->val});
        
        solve(root->left,h-1,v+1,m);
        solve(root->right,h+1,v+1,m);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root)
{
        map<int,multiset<pair<int,int>>> m;
        vector<vector<int>> ans;
        
        solve(root,0,0,m);
        
        for(auto a:m)
        {
            vector<int> temp;
            for(auto b: a.second)
            {
                temp.push_back(b.second);
            }
                ans.push_back(temp);
        }
        
        return ans;
        
}

/* Interative */
vector<vector<int>> verticalTraversal(TreeNode* root)
{
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            
            TreeNode* node=p.first;
            int x=p.second.first,y=p.second.second;
            
            m[x][y].insert(node->val);
            if(node->left)
            {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto x: m)
        {
            vector<int> temp;
            for(auto y: x.second)
            {
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }
                return ans;
}

