
class Solution {
public:
	int msf=INT_MIN;
	int get_max(TreeNode*root){
		int sum=root->val;
        int op1=0;
        int op2=0;
    	if(root->left){
            op1=get_max(root->left);
        }
    	if(root->right){
            op2=get_max(root->right);
        }
    	sum+=op1+op2;
        msf=max(msf,sum);
        return sum;
	}

    int maxPathSum(TreeNode* root){
    	get_max(root);
        return msf;
    }
};