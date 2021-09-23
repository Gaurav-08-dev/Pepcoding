typedef pair<pair<int,int>,int> p;

p zigzag(TreeNode* root)
{
    if(root==NULL) return make_pair(make_pair(-1,-1),0);
    
    p left=zigzag(root->left);
    p right=zigzag(root->right);
    
    
    int startatL=left.first.second + 1;
    int startatR= right.first.first + 1;
    
    int omax=max(max(left.second,right.second),max(startatL,startatR));
    
    return make_pair(make_pair(startatL,startatR),omax);
    
}
int longestZigZagPath(TreeNode *root)
{
    p res=zigzag(root);
    
    return res.second;
}
