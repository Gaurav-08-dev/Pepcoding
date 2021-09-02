pair<int,int> robbery(TreeNode* node)
    {
        if(node==NULL) return make_pair(0,0);
        
        pair<int,int> l=robbery(node->left);
        pair<int,int> r=robbery(node->right);
        
        int a=l.first;
        int a_=r.first;
        int b=l.second;
        int b_=r.second;
        int c= node->val;
        
        int robbed= b + b_ + c;
        
        int notRobbed=max(max(a+a_,a+b_),max(b+a_,b+b_));
        
        return make_pair(robbed,notRobbed);
    }
    

int HouseRobber(TreeNode *root)
{
    pair<int,int> p;
    p=robbery(root);
    return max(p.first,p.second);
}