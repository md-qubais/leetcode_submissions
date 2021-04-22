class Solution {
public:
    bool hasPathSum(TreeNode* root, int k,int sum){
        if(root==NULL){
            if(k==sum){
            return true;
        }
            return false;
        }
        bool ans1=hasPathSum(root->left,k,sum+root->val);
        if(ans1==true){
            return true;
        }
        bool ans2=hasPathSum(root->right,k,sum+root->val);
        if(ans2){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode*root,int k){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL and root->right==NULL){
            if(root->val==k){
                return true;
            }
            return false;
        }
        return hasPathSum(root->left,k,root->val) or hasPathSum(root->right,k,root->val);
    }
};