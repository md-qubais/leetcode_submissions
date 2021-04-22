
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root){
        if(root==NULL){
            return ans;
        }
        deque<TreeNode*> q;
        vector<int> temp;
        q.push_back(root);
        q.push_back(NULL);
        while(!q.empty()){
            TreeNode*n=q.front();
            q.pop_front();
            if(n==NULL){
                if(temp.size()>0) ans.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                if(q.size()>0) q.push_back(NULL);
                else{
                    if(temp.size()>0) ans.push_back(temp); 
                }

            }else{
                temp.push_back(n->val);
                if(n->left){
                    q.push_back(n->left);
                }
                if(n->right) q.push_back(n->right);
            }
        }
        return ans;
    }
};