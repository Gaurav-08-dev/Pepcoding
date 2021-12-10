/*** Brute force ****/

// do inroder traversal and store the val and return arr[k-1];

// TC -> O(N) , SC -> O(N)

 void inorder(TreeNode* root,vector<int> &arr){
        
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }


/*** Approach - 2 ****/
// keep a counter variable while doing inroder traversal and when count==k store the ans

void inorder(TreeNode* root,int &count,int k,int &ans){
        
        
        if(!root) return;
        inorder(root->left, count,k,ans);
        count++;
        if(k==count) ans=root->val;
        inorder(root->right,count,k,ans);
    }


/**** Approach - 3 ***/
    // use inorder Morris traversal
    