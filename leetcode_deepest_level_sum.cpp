class Solution {
public:
	int height(TreeNode*root){
		if(!root){
			return 0;
		}
		return 1+max(height(root->left),height(root->right));
	}
	int ans(TreeNode*root,int level,int k){
		if(root==NULL){
			return 0;
		}
		if(level==k){
			return root->val;
		}
		int left=ans(root->left,level,k+1);
		int right=ans(root->right,level,k+1);
		return left+right;

	}
    int deepestLeavesSum(TreeNode* root) {
    	int level=height(root);
    	return ans(root,level,1);
    }
};