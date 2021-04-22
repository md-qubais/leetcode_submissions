class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high){
    	if(!root){
    		return NULL;
    	}
    	root->left=trimBST(root->left,low,high);
    	root->right=trimBST(root->right,low,high);
    	//delete if
    	if(root->val<low or root->val>high){
    		//if it has no child
    		if(!root->left and !root->right){
    			return NULL;
    		}
    		//if it has only single child
    		if(!root->left){
    			TreeNode*temp=root;
    			
    		    return temp->right;
    		}
    		if(!root->right){
    			TreeNode*temp=root;
    			 
    			return temp->left;
    		}

    		//if the root has both the child then 
    		//choose the left max or the right min
    		TreeNode*left_max=root;
    		while(left_max->right){
    			left_max=left_max->right;
    		}
    		swap(root->val,left_max->val);
    		root->left=trimBST(root->left,low,high);
    		return root;
    	}
    	return root;
    }
};