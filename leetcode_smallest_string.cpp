class Solution {
public:
	string smallestFromLeaf(TreeNode*root,string str){
		if(!root){
			return str;
		}
		string temp="";
		temp+=(char)(97+root->val);
		string ans1="";
		if(root->left) ans1=smallestFromLeaf(root->left,temp+str);
		string ans2="";
		if(root->right) ans2=smallestFromLeaf(root->right,temp+str);
		if(ans1.length()==0 and ans2.length()==0){
			return temp+str;
		}
		if(ans1.length()==0 and ans2.length()!=0){
			return ans2;
		}
		if(ans2.length()==0 and ans1.length()!=0){
			return ans1;
		}
		return min(ans1,ans2);
	}
    string smallestFromLeaf(TreeNode* root){      
    	return smallestFromLeaf(root,"");
    }
};