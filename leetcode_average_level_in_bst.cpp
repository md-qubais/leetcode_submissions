
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> ans;
        if(root==NULL){
        	return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double num=0;
        double count=0;
        while(!q.empty()){
        	TreeNode*temp=q.front();
        	q.pop();
        	if(temp==NULL){
        		ans.push_back(num/count);
        		num=0;
        		count=0;
        		if(q.size()>0){
        			q.push(NULL);
        		}
        	}else{
        		count++;
        		num+=(double)temp->val;
        		if(temp->left) q.push(temp->left);
        		if(temp->right) q.push(temp->right);
        	}
        }
        return ans;
    }
};