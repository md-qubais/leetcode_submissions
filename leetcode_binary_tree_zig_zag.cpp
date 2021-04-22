class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    	stack<TreeNode*> s1;
    	stack<TreeNode*> s2;
    	int prev=0;
    	vector<vector<int>> ans;
    	if(root==NULL){
            return ans;
        }
        s1.push(root);
    	while(!s1.empty() or !s2.empty()){
    		vector<int> temp;
    		if(prev%2==0){
    			//go left to right
    			while(!s1.empty()){
    				temp.push_back(s1.top()->val);
    				if(s1.top()->left){
    					s2.push(s1.top()->left);
    				}
    				if(s1.top()->right){
    					s2.push(s1.top()->right);
    				}
    				s1.pop();
    			}
    			ans.push_back(temp);
    		}else{
    			//go right to left
    			while(!s1.empty()){
    				temp.push_back(s1.top()->val);
    				if(s1.top()->right) s2.push(s1.top()->right);
    				if(s1.top()->left) s2.push(s1.top()->left);
    				s1.pop();
    			}
    			ans.push_back(temp);
    		}
    		swap(s1,s2);
    		prev++;
    	}
    	return ans;
    }
};