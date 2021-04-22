class Solution {
public:
	pair<int,int> count(TreeNode*root){
		pair<int,int> p;
		if(root==NULL){
			p.first=0;
			p.second=0;
            return p;
		}
		pair<int,int> p1=count(root->left);
		pair<int,int> p2=count(root->right);
		p.first=p1.first+p2.first+1;
		p.second=p1.second+p2.second+root->val;
		return p;
	}
    int distributeCoins(TreeNode* root){
    	//first for nodes 
    	//second for total coins
    	int ans=0;
    	if(root==NULL){
    		return ans;
    	}
    	pair<int,int> p=count(root);
        int num=p.second/p.first;
        
    	return ans;
    }
};