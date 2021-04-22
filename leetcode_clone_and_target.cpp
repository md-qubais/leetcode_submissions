class Solution {
public:
	TreeNode* cloned(TreeNode*root,TreeNode*target){
		if(root==NULL){
			return NULL;
		}
		TreeNode*left=cloned(root->left,target);
		if(left){
			if(left->val==target->val) return left;
		}
		TreeNode*right=cloned(root->right,target);
		if(right){
			if(right->val==target->val) return right;
		}
		if(root->val==target->val){
			return root;
		}
		return NULL;
	}
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* clone, TreeNode* target){
    	return cloned(clone,target);
    }
};