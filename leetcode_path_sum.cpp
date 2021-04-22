class Solution{
public:
	vector<int> paths(TreeNode*root){
		if(!root){
			vector<int> ans;
			return ans;
		}
		vector<int> ans1=paths(root->left);
		vector<int> ans2=paths(root->right);
		if(ans1.size()==0 and ans2.size()==0){
			vector<int> res;
			res.push_back(root->val);
			return res;
		}
		if(ans1.size()>0 and ans2.size()==0){
			vector<int> res;
			for(auto it:ans1){
				res.push_back(it+root->val);
			}
			return res;
		}
		if(ans1.size()==0 and ans2.size()>0){
			vector<int> res;
			for(auto it:ans2){
				res.push_back(it+root->val);
			}
			return res;
		}
		vector<int> res;
		for(auto it:ans1){
			res.push_back(it+root->val);
		}
		for(auto it:ans2){
			res.push_back(it+root->val);
		}
		return res;
	}
    bool hasPathSum(TreeNode* root, int targetSum){
    	vector<int> ans=paths(root);
    	for(auto it:ans){
    		if(it==targetSum){
    			return true;
    		}
    	}
    	return false;
    }
};