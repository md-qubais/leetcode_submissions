class Solution {
public:
    TreeNode* pruneTree(TreeNode* root){
    	if(!root){
    		return NULL;
    	}
    	root->left=pruneTree(root->left);
    	root->right=pruneTree(root->right);
    	if(!root->left and !root->right and root->val==0){
    		return NULL;
    	}
    	return root;
    }
};