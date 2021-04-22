class Solution {
public:
	vector<int> path_sum(TreeNode*root){
		if(!root){
			vector<int> ans;
			return ans;
		}
		vector<int> ans1=path_sum(root->left);
		vector<int> ans2=path_sum(root->right);
		if(ans1.size()==0 and ans2.size()==0){
			vector<int> ans;
			ans.push_back(root->val);
			return ans;
		}
		if(ans1.size()>0 and ans2.size()==0){
			vector<int> ans;
			for(auto&it:ans1){
				ans.push_back(it+root->val);
			}
			return ans;
		}
		if(ans1.size()==0 and ans2.size()>0){
			vector<int> ans;
			for(auto&it:ans2){
				ans.push_back(it+root->val);
			}
			return ans;
		}
		int num=0;
		vector<int> ans;
		for(auto&it:ans1){
			num+=it;
			ans.push_back(root->val+it);
		}
		for(auto&it:ans2){
			num+=it;
			ans.push_back(root->val+it);
		}
		ans.push_back(num+root->val);
		return ans;
	}
    int maxPathSum(TreeNode* root){
    	vector<int> ans=path_sum(root);
    	int res=INT_MIN;
    	for(auto&it:ans){
    		res=max(res,it);
    	}
    	return res;//*max_element(ans.begin(),ans.end());
    }
};