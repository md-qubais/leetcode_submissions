
class Solution {
public:
    int num=0;
    TreeNode* bstToGst(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        root->right=bstToGst(root->right);
        root->val+=num;
        num=root->val;
        root->left=bstToGst(root->left);
        return root;
    }
};