class Solution {
public:
	vector<string> numbers(TreeNode*root){
		if(root==NULL){
			vector<string> ans;
			return ans;
		}
		vector<string> ans1=numbers(root->left);
		vector<string> ans2=numbers(root->right);
		string temp=to_string(root->val);
		if(ans1.size()==0 and ans2.size()==0){
			vector<string> res;
			res.push_back(temp);
			return res;
		}
	   
		if(ans1.size()>0 and ans2.size()==0){
			vector<string> res;
			for(auto it:ans1){
				res.push_back(temp+it);
			}
			return res;
		}
		if(ans2.size()>0 and ans1.size()==0){
			vector<string> res;
			for(auto it:ans2){
				res.push_back(temp+it);
			}
			return res;
		}
		vector<string> res;
		for(auto it:ans1){
			res.push_back(temp+it);
		}
		for(auto it:ans2){
			res.push_back(temp+it);
		}
		return res;
	}
    int sumNumbers(TreeNode* root){
    	vector<string> ans=numbers(root);
    	int res=0;
    	for(auto it:ans){
    		int n;
    		stringstream num(it);
    		num>>n;
    		res+=n;
    	}
    	return res;
    }
};