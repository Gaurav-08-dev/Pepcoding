/* Iterative */

 void minMAX(Node* root,int &lh,int &rh,int count)
    {
        if(!root) return;
        
        if(count<lh) lh=count;
        else if(count>rh) rh=count;
        
        minMAX(root->left,lh,rh,count-1);
        minMAX(root->right,lh,rh,count+1);
    }
    vector<int> topView(Node *root)
    {
        int lh=0,rh=0;
        
        minMAX(root,lh,rh,0);
        int width=rh - lh + 1;
        
        vector<int> ans(width);
        
        queue<pair<Node*,int>> q;
        q.push({root,abs(lh)});
        
        while(!q.empty())
        {
            pair<Node*,int> p=q.front();
            q.pop();
            
            Node* n=p.first;
            int index=p.second;
            
            if(ans[index]==0)
                ans[index]=n->data;
            
            if(n->left) q.push({n->left,index-1});
            if(n->right) q.push({n->right,index+1});
            
        }
        
        return ans;
        
    }


    /* Iterative approac - 2*/

     vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it=q.front(); q.pop();
            Node* node=it.first;
            int line=it.second;
            
            if(m.find(line)==m.end()) m[line]=node->data;
            
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto y: m)
        {
            ans.push_back(y.second);
        }
        return ans;
    }


/* recursive */
        void minMAX(Node* root,map<int,pair<int,int>> &m,int level,int distance)
    {
        if(!root) return;
        if(m.find(distance)==m.end() or level < m[distance].second)
            m[distance]={root->data,level};
        
        minMAX(root->left,m,level+1,distance-1);
        minMAX(root->right,m,level+1,distance+1);
    }
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,pair<int,int>> m;
        minMAX(root,m,0,0);
        for(auto y: m)
        {
            ans.push_back(y.second.first);
        }
        return ans;
    }