class Solution {
public:
	vector<vector<int>> sum(TreeNode*root){
		if(!root){
			vector<vector<int>> ans;
			return ans;
		}
		vector<vector<int>> ans1=sum(root->left);
		vector<vector<int>> ans2=sum(root->right);
		if(ans1.size()==0 and ans2.size()==0){
			vector<int> temp;
			temp.push_back(root->val);
			vector<vector<int>> ans;
			ans.push_back(temp);
			return ans;
		}
		if(ans1.size()>0 and ans2.size()==0){
			vector<vector<int>> ans;
			for(int i=0;i<ans1.size();i++){
				ans1[i].push_back(root->val);
				ans.push_back(ans1[i]);
			}
			return ans;
		}
		if(ans2.size()>0 and ans1.size()==0){
			vector<vector<int>> ans;
			for(int i=0;i<ans2.size();i++){
				ans2[i].push_back(root->val);
				ans.push_back(ans2[i]);
			}
			return ans;
		}
		vector<vector<int>> ans;
		for(int i=0;i<ans1.size();i++){
			ans1[i].push_back(root->val);
		}
		for(int i=0;i<ans2.size();i++){
			ans2[i].push_back(root->val);
		}
		for(int i=0;i<ans1.size();i++){
			ans.push_back(ans1[i]);
		}
		for(int i=0;i<ans2.size();i++){
			ans.push_back(ans2[i]);
		}
		return ans;
	}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    	vector<vector<int>> ans;
    	if(!root){
    		return ans;
    	}
    	vector<vector<int>> temp=sum(root);
    	for(auto it:temp){
    		int tot=0;
    		for(auto jt:it){
    			tot+=jt;
    		}
    		if(tot==targetSum){
    			vector<int> res=it;
    			reverse(res.begin(),res.end());
    			ans.push_back(res);
    		}
    	}

    	return ans;
    }
};