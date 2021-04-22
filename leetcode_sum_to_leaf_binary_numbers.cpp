class Solution {
public:
	vector<string> getbinary(TreeNode*root){
		if(root==NULL){
			vector<string> emp;
			return emp;
		}
		vector<string> op1=getbinary(root->left);
		vector<string> op2=getbinary(root->right);
		if(op1.size()==0 and op2.size()==0){
			vector<string> res;
			res.push_back(to_string(root->val));
			return res;
		}
		if(op1.size()>0 and op2.size()==0){
			for(auto&it:op1){
				it=to_string(root->val)+it;
			}
			return op1;
		}
		if(op2.size()>0 and op1.size()==0){
			for(auto&it:op2){
				it=to_string(root->val)+it;
			}
			return op2;
		}
		vector<string> res;
		for(auto it:op1){
			res.push_back(to_string(root->val)+it);
		}
		for(auto it:op2){
			res.push_back(to_string(root->val)+it);
		}
		return res;
	}
    int sumRootToLeaf(TreeNode* root){
    	vector<string> temp=getbinary(root);
    	int ans=0;
    	for(auto&it:temp){
    		bitset<1000> bits(it);
    		ans+=bits.to_ulong();
    	}
    	return ans;
    }
};