/* O(N^2)*/

    void find_max_min(Node* root,int *lh,int *rh,int count)
    {
        if(!root) return;
        
        if(count<*lh) *lh=count;
        else if(count > *rh) *rh=count;
        
        find_max_min(root->left,lh,rh,count-1);
        find_max_min(root->right,lh,rh,count+1);
    }
    
    void traverse(Node* root,vector<int> &ans,int line_no,int count)
    {
        if(!root) return;
        
        if(line_no == count)
            ans.push_back(root->data);
            
            traverse(root->left,ans,line_no,count-1);
            traverse(root->right,ans,line_no,count+1);
    }
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        int lh=0,rh=0;
        find_max_min(root,&lh,&rh,0);
        
        for(int i=lh;i<=rh;i++)
        {
            traverse(root,ans,i,0);
        }
        
        return ans;
    }


/* using map -. problem of ordering */


    void getorder(Node* root,int count,map<int,vector<int>> &m)
    {
        if(!root) return;
        
        m[count].push_back(root->data);
        
        getorder(root->left,count-1,m);
        getorder(root->right,count+1,m);
    }
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> m;
        
        getorder(root,0,m);
        
        vector<int> ans;
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            // vector<int> temp;
            for(int i=0;i<it->second.size();i++)
            {
                ans.push_back(it->second[i]);
            }
            
        }
        return ans;
    }


/* using unordered map*/

    vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
        if(!root) return ans;
        
        
        unordered_map<int,vector<int>> m;
        int count=0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root,count});
        
        int mn=0,mx=0;
        
        while(q.size()>0)
        {
            pair<TreeNode*,int> p=q.front(); q.pop();
            count=p.second;
            TreeNode* n=p.first;
            
            m[count].push_back(n->val);
            
            if(n->left) q.push({n->left,count-1});
            if(n->right) q.push({n->right,count+1});
            
            if(mn>count) mn=count;
            else if(mx<count) mx=count;
        }
        
        for (int i=mn;i<=mx;i++)
    {
        ans.push_back(m[i]);;
      
    }    
    return ans;
}