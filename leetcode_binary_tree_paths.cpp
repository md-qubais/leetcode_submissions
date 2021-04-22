class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root){
    	if(root==NULL){
    		vector<string> arr;
    		return arr;
    	}
    	vector<string> op1=binaryTreePaths(root->left);
    	vector<string> op2=binaryTreePaths(root->right);
    	if(op1.size()==0 and op2.size()==0){
    		vector<string> ans;
    		ans.push_back(to_string(root->val));
    		return ans;
    	}
    	if(op1.size()>0 and op2.size()==0){
    		vector<string> res;
    		for(auto it:op1){
    			res.push_back(to_string(root->val)+"->"+it);
    		}
    		return res;
    	}
    	if(op2.size()>0 and op1.size()==0){
    		vector<string> res;
    		for(auto it:op2){
    			res.push_back(to_string(root->val)+"->"+it);
    		}
    		return res;
    	}
    	vector<string> res;
    	for(auto it:op1){
    		res.push_back(to_string(root->val)+"->"+it);
    	}
    	for(auto it:op2){
    		res.push_back(to_string(root->val)+"->"+it);
    	}
    	return res;
    }
};