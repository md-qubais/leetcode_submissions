class Solution {
public:
    int maxPathSum(TreeNode* root){
    	if(!root){
    		return INT_MIN;
    	}
    	int ans1=maxPathSum(root->left);
    	int ans2=maxPathSum(root->right);
    	if(ans1==INT_MIN and ans2==INT_MIN){
    		return root->val;
    	}
    	if(ans1==INT_MIN){
    		return max(root->val,max(ans2,ans2+root->val));
    	}
    	if(ans2==INT_MIN){
    		return max(root->val,max(ans1,ans1+root->val));
    	}
    	return max(root->val,max(ans1,max(ans2,max(ans1+ans2+root->val,max(root->val+ans1,root->val+ans2)))));
    }
};