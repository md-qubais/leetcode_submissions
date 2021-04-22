class Solution {
public:
    void verticalTraversal(TreeNode*root,int n,map<int,vector<int>>&m){
        if(root==NULL){
            return ;
        }
        m[n].push_back(root->val);
        verticalTraversal(root->left,n-1,m);
        verticalTraversal(root->right,n+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            vector<vector<int>> ans;
            return ans;
        }
        map<int,vector<int>> m;
        verticalTraversal(root,0,m);
        vector<vector<int>> ans(m.size());
        int i=0;
        for(auto it:m){
            for(auto jt:it.second){
                ans[i].push_back(jt);
            }
            sort(ans[i].begin(),ans[i].end());
            i++;
        }
        return ans;
    }
};