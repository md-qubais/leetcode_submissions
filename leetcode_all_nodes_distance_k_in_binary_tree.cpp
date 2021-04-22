class Solution {
public:
	vector<int> res;
vector<TreeNode*> node_to_root_roots(TreeNode*root,TreeNode*k){
	vector<TreeNode*> res;
	if(!root){
		return res;
	}
	if(root==k){
		res.push_back(root);
		return res;
	}
	vector<TreeNode*> left=node_to_root_roots(root->left,k);
	if(left.size()>0){
		for(auto it:left){
			res.push_back(it);
		}
		res.push_back(root);
		return res;
	}
	vector<TreeNode*> right=node_to_root_roots(root->right,k);
	if(right.size()>0){
		for(auto it:right){
			res.push_back(it);
		}
		res.push_back(root);
		return res;
	}
	return res;
}
    void get_kth_element(TreeNode*root,int k,TreeNode*target){
    	if(!root or k<0 or root==target){
    		return;
    	}
    	if(k==0){
    		res.push_back(root->val);
    		return;
    	}
    	get_kth_element(root->left,k-1,target);
    	get_kth_element(root->right,k-1,target);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    	if(!root or !target){
    		return res;
    	}
    	vector<TreeNode*> paths=node_to_root_roots(root,target);  
    	for(int i=0;i<paths.size() and i<=k ;i++){
    		get_kth_element(paths[i],k-i,i==0?NULL:paths[i-1]);
    	}
    	return res;    
    }
};