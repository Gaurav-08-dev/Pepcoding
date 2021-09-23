
class BSTIterator
{
    stack<TreeNode*> s;
    void leftNodes(TreeNode* root)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
    }
public:
  BSTIterator(TreeNode* root)
  {
    leftNodes(root);
  }

  int next()
  {
    TreeNode* topNode=s.top(); s.pop();
    
    if(topNode->right) 
        leftNodes(topNode->right);
    
    return topNode->val;
  }

  bool hasNext()
  {
    return s.size() > 0;
  }
};


/* Using vector */
class BSTIterator {
    
    vector<int> s;
    int index=0;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        s.push_back(root->val);
        inorder(root->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        index++;
        return s[index-1];
    }
    
    bool hasNext() {
        
        return index!=s.size();
    }
};