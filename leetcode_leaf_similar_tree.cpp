class Solution {
public:
	vector<int> get_leaves(TreeNode*root){
		vector<int> res;
		if(!root->left and !root->right){
			res.push_back(root->val);
			return res;
		}
		vector<int> op1=get_leaves(root->left);
		vector<int> op2=get_leaves(root->right);
		for(auto&it:op1){
			res.push_back(it);
		}
		for(auto&it:op2){
			res.push_back(it);
		}
		return res;
	}
    bool leafSimilar(TreeNode* root1, TreeNode* root2){
    	vector<int> tree1=get_leaves(root1);
    	vector<int> tree2=get_leaves(root2);
    	if((tree1.size()>tree2.size()) or (tree2.size()>tree1.size())){
    		return false;
    	}
    	for(int i=0;i<tree1.size();i++){
    		if(tree1[i]!=tree2[i]){
    			return false;
    		}
    	}
    	return true;
    }
};