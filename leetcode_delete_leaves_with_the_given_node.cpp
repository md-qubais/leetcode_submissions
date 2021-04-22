
class Solution {
public:
	TreeNode* post_order_remove(TreeNode*root,int k){
		if(root==NULL){
			return NULL;
		}
		root->left=post_order_remove(root->left,k);
		root->right=post_order_remove(root->right,k);
		if(root->left==NULL and root->right==NULL and root->val==k){
			return NULL;
		}
		return root;
	}
    TreeNode* removeLeafNodes(TreeNode* root, int target){
    	//here we cant perform preorder
    	//if w perform preorder it will delete only leaves
    	//with the given target not the nodes that will become
    	//leaves nodes after deleting its targat child leave node
    	return post_order_remove(root,target);	
    }
};