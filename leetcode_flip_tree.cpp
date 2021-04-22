
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2){
    	if(!root1 and !root2){
    		return true;
    	}
    	if(root1 and !root2){
    		return false;
    	}
    	if(root2 and !root1){
    		return false;
    	}
    	if(root1->left != root2->left and root1->right!=root2->right ){
    		swap(root2->left,root2->right);
    	}
    	if(root1->left==root2->left and root2->right==root1->right){
    		bool ans1=flipEquiv(root1->left,root2->left);
    		bool ans2=flipEquiv(root1->right,root2->right);
    	}
    	if(ans1 and ans2){
    		return true;
    	}
    	return false;
    }
};