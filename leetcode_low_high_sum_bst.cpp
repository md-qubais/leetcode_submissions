class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high){
    	if(!root){
    		return 0;
    	}
    	int op1=rangeSumBST(root->left,low,high);
    	int op2=rangeSumBST(root->right,low,high);
    	if(root->val>=low and root->val<=high){
    		return op1+op2+root->val;
    	}
    	return op1+op2;
    }
};