
class Solution {
public:
    int ans=0;
    void find_path(TreeNode*root,int sum,int tot=0,string str=""){
        if(!root) return;
        if(tot+root->val==sum){
            ans++;
            
        }
        find_path(root->left,sum,tot+root->val,str+to_string(root->val)+" ");
        find_path(root->right,sum,tot+root->val,str+to_string(root->val)+" ");
    }
    void helper(TreeNode*root,int sum){
        if(!root) return;
        helper(root->left,sum);
        helper(root->right,sum);
        find_path(root,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        helper(root,sum);
        return ans;
    }
};