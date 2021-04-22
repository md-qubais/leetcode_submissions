class Solution{
public:
    vector<int> largestValues(TreeNode* root){
        int curr=INT_MIN;
        vector<int> ans;
        deque<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push_back(root);
        q.push_back(NULL);
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop_front();
            if(temp==NULL){
                ans.push_back(curr);
                if(q.size()>0){
                    q.push_back(NULL);
                }
                curr=INT_MIN;
            }else{
                curr=max(temp->val,curr);
                if(temp->left) q.push_back(temp->left);
                if(temp->right) q.push_back(temp->right);
            }
        }
        return ans;
    }
};