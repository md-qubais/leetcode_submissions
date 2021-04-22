
class Solution {
public:
    string tree2str(TreeNode* root){
    	if(!root){
    		return "";
    	}
    	string op1=tree2str(root->left);
    	string op2=tree2str(root->right);
    	if(op1.length()==0 and op2.length()==0){
    		return to_string(root->val);
    	}
    	if(op1.length()>0 and op2.length()==0){
    		return to_string(root->val)+"("+op1+")";
    	}
    	if(op2.length()>0 and op1.length()==0){
    		return to_string(root->val)+"()"+"("+op2+")";
    	}
    	return to_string(root->val)+"("+op1+")"+"("+op2+")";
    }
};