
class Solution {
public:
    vector<int> ans;
    void pre_help(Node*root){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        for(auto it:root->children){
            pre_help(it);
        }

    }
    vector<int> preorder(Node* root){
        pre_help(root);
        return ans;
    }
};