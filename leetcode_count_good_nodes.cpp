class Solution {
public:
	int ans=0;
    void count(TreeNode*root,int Max){
		if(!root){
			return;
		}
		if(root->left){
			if(root->left->val>=Max){
				ans++;
				count(root->left,root->left->val);
			}else{
				count(root->left,Max);
			}
		}
		if(root->right){
			if(root->right->val>=Max){
				ans++;
				count(root->right,root->right->val);
			}else{
				count(root->right,Max);
			}
		}
	}
    int goodNodes(TreeNode* root){
    	if(!root){
    		return 0;
    	}
        count(root,root->val);
    	return ans+1;
    }
};