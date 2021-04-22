class Solution {
public:
    vector<int> ans;
    int max_level=0;
    vector<int> rightSideView(TreeNode* root,int level=1){
        if(!root) return ans;
        if(level>max_level){
            ans.push_back(root->val);
            max_level=level;
        }
        rightSideView(root->right,level+1);
        rightSideView(root->left,level+1);
        return ans;
    }
};