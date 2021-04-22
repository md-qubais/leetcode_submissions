class Solution {
public:
	int helper(TreeNode*root){
		if(root==NULL){
			return 0;
		}
	}
    int sumOfLeftLeaves(TreeNode* root){
    	return helper(root->left)+helper(root->right);
    }
};