class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    	if(root==p){
    		return root;
    	}
    	if(root==q){
    		return q;
    	}
    	if(){

    	}
    	TreeNode*left=lowestCommonAncestor(root->left,p,q);
    	TreeNode*right=lowestCommonAncestor(root->right,p,q);
    }
};